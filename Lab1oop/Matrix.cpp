#include <stdlib.h>
#include<stdio.h>
#include <iostream>
#include <crtdbg.h>
#include "Matrix.h"


namespace Prog1 {

    void create_new_node(struct Node** start, int non_zero_element, int row_index, int column_index) {

        struct Node* temp, * r;
        temp = *start;

        if (temp == NULL) {
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->value = non_zero_element;
            temp->row_position = row_index;
            temp->column_postion = column_index;
            temp->next = NULL;
            *start = temp;
        }

        else {
            while (temp->next != NULL) {
                temp = temp->next;
            }

            r = (struct Node*)malloc(sizeof(struct Node));
            r->value = non_zero_element;
            r->row_position = row_index;
            r->column_postion = column_index;
            r->next = NULL;
            temp->next = r;
        }
    }



    void DeleteList(struct Node* start) {
        struct Node* r;
        r = start;

        while (start != NULL) {
            start = r->next;
            delete r;
            r = start;
        }

    }

    void PrintMatr(struct Node* start, int p, int l) {
        struct Node* end = NULL;
        end = start;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < l; j++) {
                if ((i == end->row_position) && (j == end->column_postion)) {
                    std::cout << end->value << " ";
                    if (end->next != NULL)
                        end = end->next;
                }
                else {
                    std::cout << "0 ";
                }
            }
            std::cout << "\n";
        }
    }

    Node* input(int p, int l) {
        struct Node* initmatr = NULL;
        int k, line, numinl;
        for (int j = 0; j < l * p; j++) {
            std::cout << "In which line do you want to add non-zero elem?" << std::endl;
            std::cin >> line; std::cout << std::endl;
            if (line == -1)
                break;
            std::cout << "In which pos in line?" << std::endl;
            std::cin >> numinl; std::cout << std::endl;
            if ((line == -1) || (numinl == -1)) {
                break;
            }
            std::cout << "Enter the value of elem" << std::endl;
            do {
                if (!(std::cin >> k))
                    break;
            } while (k < -1);

            if (k > 0) {
                create_new_node(&initmatr, k, line, numinl);
            }
        }
        return initmatr;
    }


    Node* modify(struct Node* start, int p, int l) {
        struct Node* newmatr = NULL;
        struct Node* tmp = NULL;
        struct Node* end = NULL;
        int min;
        int column_number;
        int lever;
        for (int i = 0; i < p; i++) { // ѕроходимс€ по строкам
            end = start;
            tmp = start;
            min = 9999;
            lever = 0;
            for (int j = 0; j < l; j++) { // ѕроходимс€ по одной строке i
                while (end != 0) { // ѕросматриваем список
                    if (i == end->row_position) { // ≈сли элемент находитс€ в нужной нам строке
                        if (end->value < min) { // ≈сли какой-то из элементов меньше текущего минмального - переназначаем минимальный
                            min = end->value;
                            column_number = end->column_postion;
                        }
                    }
                    end = end->next;
                }
            for (int j = 0; j < l; j++) { // —нова проходимс€ по одной строке i
                do {
                    while (tmp != 0) { // проходимс€ по списку
                            if ((tmp->value == min) && (i == tmp->row_position)) { // если нашли наш минимальный элемент и он в нашей строке
                                while (tmp != 0) { // проходимс€ по списку до конца
                                    if (i == tmp->row_position) { // если элемент в нашей строке
                                        create_new_node(&newmatr, tmp->value, i, column_number); // вставл€ем элемент в новый список
                                        column_number++;
                                    }
                                    lever = 1; // если нашли минимальный - рычаг = 1 
                                    tmp = tmp->next;
                            }
                        }
                        if (lever != 1) { // если минимальный не найден - просто проходимс€ по списку
                            tmp = tmp->next;
                        }
                        if (tmp == 0 ) { // ≈сли дошли до конца списка и не нашли минимальный - создаем условие дл€ выхода из цикла
                            lever = 1;
                        }
                    }
                } while (lever != 1);
            }
        }
        }
        return newmatr; // ¬озвращаем новую матрицу в программу

    }

}