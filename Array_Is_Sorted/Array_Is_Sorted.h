/**
 * @brief checks if array is sorted
 * @details calls correct sort checker (increasingly or decreasingly)
*
 * @param arr array to be checked
 * @param size size of array
 *
 * @return true if sorted, false if not
 */
bool isSorted(int* arr, int size);

/**
 * @brief checks if sorted increasingly
 * @details first element is smallest, equal elements okay
 *
 * @param arr array to be checked
 * @param size orig size
 *
 * @return true & print "increasing sort" if sorted, false if not
 */
bool isInc(int* arr, int size);

/**
 * @brief checks if sorted decreasingly
 * @details first element is largest, equal elements okay
 *
 * @param arr array to be checked
 * @param size orig size
 *
 * @return true & print "decreasing sort" if sorted, false if not
 */
bool isDec(int* arr, int size);
