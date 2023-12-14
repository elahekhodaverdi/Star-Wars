#include "game.hpp"
using namespace std;
Game::Game(Window *_win)
{
    win = _win;
    game_running = true;
}

void Game::process_events()
{
    while (win->has_pending_event())
    {
        Event event = win->poll_for_event();
        switch (event.get_type())
        {
        case Event::QUIT:
            game_running = false;
            exit(0);
            break;
        case Event::KEY_PRESS:
            player.handle_key_press(event.get_pressed_key());
            break;
        case Event::KEY_RELEASE:
            player.handle_key_release(event.get_pressed_key());
            break;
        }
    }
}

void Game::move_objects()
{
    player.move();
    player.bullet_move();
    enemies.move_enemies();
}

void Game::draw_board()
{
    win->clear();
    win->draw_img(WINDOW_FILENAME);
    player.draw_object(win, PLAYER_FILENAME);
    player.draw_bullets(win, PLAYER_BULLEET_FILENAME);
    enemies.draw_enemies(win);
    hostages.draw_hostages(win);

    win->update_screen();
}

void Game::fix_element_in_window(int current_map)
{
    for (int i = 0; i < maps[current_map].map.size(); i++)
    {
        for (int j = 0; j < maps[current_map].map[0].size(); j++)
        {
            if (maps[current_map].map[i][j] == 'E')
                enemies.add_enemy(Enemy({j * BOARD_EXTENSION, i * BOARD_EXTENSION, SPACESHIP_WIDTH, SPACESHIP_HEIGTH}, STATIC));
            if (maps[current_map].map[i][j] == 'M')
                enemies.add_enemy(Enemy({j * BOARD_EXTENSION, i * BOARD_EXTENSION, SPACESHIP_WIDTH, SPACESHIP_HEIGTH}, MOVING));
            if (maps[current_map].map[i][j] == 'S')
                hostages.add_hostage(Spaceship({j * BOARD_EXTENSION, i * BOARD_EXTENSION, SPACESHIP_WIDTH, SPACESHIP_HEIGTH}, 0, 0));
        }
    }
}

void Game::read_file(char *map_filename)
{
    int length, width, round;
    ifstream input_csv(map_filename);
    input_csv >> length >> width >> round;
    win = new Window(width * BOARD_EXTENSION, length * BOARD_EXTENSION, "RSDL");
    get_maps(input_csv, round, length, width);
}

void Game::get_maps(ifstream &input_csv, int round, int length, int width)
{
    vector<map_s> maps_;
    map_s one_map;
    string line;
    for (int i = 0; i < round; i++)
    {
        for (int j = 0; j < length; j++)
        {
            input_csv >> line;
            one_map.map.push_back(line);
        }
        input_csv >> line;
        one_map.level = line;
        maps_.push_back(one_map);
        one_map.map.clear();
        one_map.level.clear();
        if (i < round)
            input_csv >> line;
    }
    maps = maps_;
}

void Game::hit()
{
    int bullet_index;
    enemies.hit_enemies(&player);
    hostages.hit_hostages(&player);
    if (player.get_state() == DEAD)
    {
        game_running = false;
    }
}

void Game::handle_being_on_screen()
{
    enemies.handle_being_on_screen_enemies(win);
    player.handle_being_on_screen_player(win);
}

void Game::update_objects(int &duration)
{
    hit();
    handle_being_on_screen();
    enemies.erase_dead_enemies();
    enemies.shoot_enemies(duration);
}

void Game::clean_map()
{
    hostages.clear_hostages();
    enemies.clear_enemies();
}

void Game::end_of_game(State state)
{
    win->clear();
    if (state == ALIVE)
        win->draw_img(WIN_IMAGE, {win->get_width() / 2 - win->get_height() / 2, 0, win->get_height(), win->get_height()});
    else
        win->draw_img(LOSE_IMAGE, {win->get_width() / 2 - win->get_height() / 2, 0, win->get_height(), win->get_height()});

    win->update_screen();
    delay(END_GAME_MESSAGE);
}

void Game::run(char *map_filename)
{
    srand(time(NULL));
    read_file(map_filename);
    int shoot_duration = 0;
    int x_location;
    for (int i = 0; i < maps.size(); i++)
    {
        x_location = rand() % (win->get_width() - SPACESHIP_WIDTH);
        player = Player({SPACESHIP_WIDTH / 2 + x_location, win->get_height() - SPACESHIP_HEIGTH / 2, SPACESHIP_WIDTH, SPACESHIP_HEIGTH}, 0, 0);
        fix_element_in_window(i);
        while (game_running)
        {
            shoot_duration += 1;
            process_events();
            update_objects(shoot_duration);
            move_objects();
            draw_board();
            if (enemies.get_number_of_enemies() == 0)
                break;
            delay(UPDATE_DELAY);
        }
        if (player.get_state() == DEAD)
            break;
        clean_map();
    }
    end_of_game(player.get_state());
}