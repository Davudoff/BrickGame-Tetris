#include "tetris_test.h"




static int test_run(Suite* suite) {
  int testResult = 0;

  SRunner* srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  testResult = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return testResult;
}



int main(){
    int result = 0;

    result = test_run(game_state_init_suite());





    return (result == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}