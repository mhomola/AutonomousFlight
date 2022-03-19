/*
 * Copyright (C) Roland Meertens
 *
 * This file is part of paparazzi
 *
 */
/**
 * @file "modules/orange_avoider/orange_avoider.h"
 * @author Roland Meertens
 * Example on how to use the colours detected to avoid orange pole in the cyberzoo
 */

#ifndef DYNAMIC_WINDOW_H
#define DYNAMIC_WINDOW_H

// settings
extern float oa_color_count_frac;

// functions
extern void dynamic_window_init(void);
extern void dynamic_window_periodic(void);


#endif

