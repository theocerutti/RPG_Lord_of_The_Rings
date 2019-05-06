/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** LIB
*/

void swap_values(int *array, int size)
{
    int stock = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1]) {
            stock = array[i];
            array[i] = array[i - 1];
            array[i - 1] = stock;
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int j = 0; j < size; j++)
        swap_values(array, size);
}
