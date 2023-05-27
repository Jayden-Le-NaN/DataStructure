#include "basic_function.h"
static unsigned int BF_LINE_LENGTH = 30;
/*
 * @brief           compare lhs and rhs, and then return the max data
 * @author          JAYDEN_NAN
 */
int BF_maxInt(int lhs, int rhs) {
    return (lhs > rhs ? lhs : rhs);
}

/*
 * @brief           print a line which length is BF_LINE_LENGTH
 * @author          JAYDEN_NAN
 */
void BF_PrintLine() {
    for (int i = 0; i < BF_LINE_LENGTH; ++i)
        putchar('-');
    putchar('\n');
}

/*
 * @brief           set the BF_LINE_LENGTH
 * @parameter len   the new length of the line
 * @author          JAYDEN_NAN
 */
void BF_PrintLineSetLength(const unsigned int len) {
    BF_LINE_LENGTH = len;
}
