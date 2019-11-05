#include "edit_distance_dyn.h"

/**
 * Return lower values
 *
 * @param x
 * @param y
 * @param z
 * @return
 */
static int lower(int x, int y, int z){
  if(x <= y && x <= z) return x;
  if(y <= x && y <= z) return y;
  return z;
} //lower

/**
 * Recursive function of edit_distance_dyn
 *
 * @param s1
 * @param s2
 * @param s1_pos
 * @param s2_pos
 * @param dyndist
 * @return
 */
int edit_distance_dyn_recursive(char *s1, char *s2, int s1_pos, int s2_pos, int **dyndist){
  if(s1_pos == 0) return s2_pos;
  if(s2_pos == 0) return s1_pos;

  if(s1[s1_pos-1] == s2[s2_pos-1]) return edit_distance_dyn_recursive(s1, s2, s1_pos-1, s2_pos-1, dyndist);

  if(dyndist[s1_pos-1][s2_pos-1] == -1) dyndist[s1_pos-1][s2_pos-1] = 1 + edit_distance_dyn_recursive(s1, s2, s1_pos-1, s2_pos-1, dyndist);
  if(dyndist[s1_pos-1][s2_pos]   == -1) dyndist[s1_pos-1][s2_pos]   = 1 + edit_distance_dyn_recursive(s1, s2, s1_pos-1, s2_pos,   dyndist);
  if(dyndist[s1_pos][s2_pos-1]   == -1) dyndist[s1_pos][s2_pos-1]   = 1 + edit_distance_dyn_recursive(s1, s2, s1_pos,   s2_pos-1, dyndist);

  return dyndist[s1_pos][s2_pos] = lower(dyndist[s1_pos-1][s2_pos-1],
                                         dyndist[s1_pos-1][s2_pos],
                                         dyndist[s1_pos][s2_pos-1]);
} //edit_distance_dyn_recursive

/**
 * Edit Distance function (dynamic version)
 *
 * @param s1
 * @param s2
 * @return
 */
int edit_distance_dyn(char *s1, char *s2){
  int s1_lenght = strlen(s1) + 1;
  int s2_lenght = strlen(s2) + 1;

  int **dyndist = malloc(s1_lenght * sizeof(int*));
  int second_size = s2_lenght * sizeof(int);
  for(int x = s1_lenght; x--; ){
    dyndist[x] = malloc(second_size);
    for(int y = s2_lenght; y--; ) dyndist[x][y] = -1;
  }

  int to_ret = edit_distance_dyn_recursive(s1, s2, s1_lenght, s2_lenght, dyndist);

  for(int z = s1_lenght; z--;) free(dyndist[z]);
  free(dyndist);

  return to_ret;
} //edit_distance_dyn
