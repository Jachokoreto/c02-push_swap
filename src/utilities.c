/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:07:45 by jatan             #+#    #+#             */
/*   Updated: 2022/02/06 00:31:49 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void printArray(int arr[], int size)
{
    int i;

    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
