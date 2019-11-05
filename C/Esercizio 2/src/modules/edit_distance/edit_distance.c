#include "edit_distance.h"

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
 * Recursive function of edit_distance
 *
 * @param s1
 * @param s2
 * @param s1_pos
 * @param s2_pos
 * @return
 */
int edit_distance_recursive(char *s1, char *s2, int s1_pos, int s2_pos){
  if(s1_pos == 0) return s2_pos;
  if(s2_pos == 0) return s1_pos;

  if(s1[s1_pos-1] == s2[s2_pos-1]) return edit_distance_recursive(s1, s2, s1_pos-1, s2_pos-1);

  return 1 + lower(edit_distance_recursive(s1, s2, s1_pos-1, s2_pos-1),
                   edit_distance_recursive(s1, s2, s1_pos-1, s2_pos),
                   edit_distance_recursive(s1, s2, s1_pos, s2_pos-1));
} //edit_distance_recursive

/**
 * Edit Distance function
 *
 * @param s1
 * @param s2
 * @return
 */
int edit_distance(char *s1, char *s2){
  int s1_lenght = strlen(s1);
  int s2_lenght = strlen(s2);
  return edit_distance_recursive(s1, s2, s1_lenght, s2_lenght);
} //edit_distance
