#include "tetris_test.h"

#include <stdio.h> //////////  After clear


START_TEST(test_1) 
{ 
  game_state_init();
  set_pause(0);
  UserAction_t action = Start;
  userInput(action, false);
  action = Down;
  userInput(action, false);
  action = Action;
  userInput(action, false);
  action = Left;
  userInput(action, false);
  action = Right;
  userInput(action, false);
  action = Down;
  userInput(action, false);
  action = Right;
  userInput(action, false);
  action = Down;
  for(int i = 0; i < 200; i++)
    userInput(action, false);
  action = Start;
  userInput(action, false);
  action = Left;
  for(int i = 0; i < 6; i++)
    userInput(action, false);
  action = Down;
  for(int i = 0; i < 200; i++)
    userInput(action, false);
  action = Left;
  for(int i = 0; i < 3; i++)
    userInput(action, false);
  action = Down;
  for(int i = 0; i < 200; i++)
    userInput(action, false);

  update_interval(5);
  game_state_remove();
}
END_TEST


Suite* game_state_init_suite(void) {
  Suite *suite = suite_create("\033[32m game_state_init \033[0m");
  TCase *tcase = tcase_create("\033[31m game_state_init \033[0m");

  tcase_add_test(tcase, test_1);

  suite_add_tcase(suite, tcase);

  return suite;

}






















