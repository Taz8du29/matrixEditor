/* menuEntries.cpp
 *
 * Callback function for every item defined under menuEntries.h
 *
 * Copyright 2018 (C) Taz8du29
 * Refer to LICENSE.md for more infos about copyright
*/


#ifndef _MENUENTRIES_CPP_
#define _MENUENTRIES_CPP_

#include "menuEntries.h"


/* CLASS "Menu" */

Menu::Menu(uint16_t x, uint16_t y, uint16_t w, uint16_t h) :
    Fl_Menu_Bar(x, y, w, h)
{
    this->box(FL_FLAT_BOX);
    this->color(fl_rgb_color(MenuColors.bg));
    this->selection_color(fl_rgb_color(MenuColors.select));

    this->textcolor(fl_rgb_color(MenuColors.text));
    // this->textfont(FL_COURIER);
    this->textfont(FL_SCREEN);
    this->textsize(11);

    this->menu(__menu);
}

Application* Menu::mainWindow(Fl_Widget* wdg)
{
    return (Application*) wdg->window();
}


/* CLASS "Menu" CALLBACKS" */

/*
 * Placeholder callback
*/
void Menu::foo(Fl_Widget*, void*) {}


/*
 * File operation (open, save and export) callbacks
*/
void Menu::cb_open(Fl_Widget* wdg, void*)
{
    char* path = fl_file_chooser("Select File", "MatrixNecklace sequence file (*.mnl)", ".");
    logs->append("Open file: ");
    logs->append(path);
}

void Menu::cb_save(Fl_Widget* wdg, void* as)
{
    // Get a pointer to ledMatrix, and pass it to getData()
    Matrix* matrix = Menu::mainWindow(wdg)->ledMatrix;
    Matrix::getData(matrix);
}

void Menu::cb_export(Fl_Widget* wdg, void* as) {}


/*
 * Edit menu callbacks
*/
void Menu::cb_undo(Fl_Widget* wdg, void*) {}
void Menu::cb_redo(Fl_Widget* wdg, void*) {}

void Menu::cb_rand(Fl_Widget* wdg, void*)
{
    // Initialize local variables
    uint64_t randomized;
    Matrix* matrix = Menu::mainWindow(wdg)->ledMatrix;

    // Randomize !
    std::random_device seed;
    std::mt19937_64 gen(seed());
    randomized = (uint64_t) gen();

    // Write to matrix
    Matrix::setData(matrix, randomized);
}

void Menu::cb_clear(Fl_Widget* wdg, void*)
{
    // Get pointer to matrix, and write 0x0 to it
    Matrix* matrix = Menu::mainWindow(wdg)->ledMatrix;
    Matrix::setData(matrix, 0x0ul);
}


/*
 * Help menu callbacks
*/
void Menu::cb_help(Fl_Widget* wdg, void*) {}
void Menu::cb_faq(Fl_Widget* wdg, void*) {}
void Menu::cb_license(Fl_Widget* wdg, void*) {}
void Menu::cb_about(Fl_Widget* wdg, void*) {}


/*
 * Miscellanous callbacks
*/
void Menu::cb_prefs(Fl_Widget* wdg, void*) {}
void Menu::cb_quit(Fl_Widget* wdg, void*) {}


#endif  /* !_MENUENTRIES_CPP_ */
