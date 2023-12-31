/* 
 * pongoOS - https://checkra.in
 * 
 * Copyright (C) 2019-2023 checkra1n team
 *
 * This file is part of pongoOS.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */
#include <pongo.h>
extern void set_timer_reg(uint64_t v);
extern void set_timer_ctr(uint64_t v);

void timer_enable() {
    set_timer_reg(1); // turn on timer

}
void timer_disable() {
    set_timer_reg(2); // turn off timer
}

#define LLKTRW_QUANTA 24000 // 1ms quanta
char timer_inited = 0;

void timer_rearm() {
    set_timer_ctr(LLKTRW_QUANTA);
}

void timer_init() {
    set_timer_reg(2); // turn off timer
    set_timer_ctr(0xfffffff);
    set_timer_reg(1); // turn on timer
    timer_inited = 1;
}
