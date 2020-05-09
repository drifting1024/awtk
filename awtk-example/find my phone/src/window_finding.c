/**
 * File:   window_animator.c
 * Author: AWTK Develop Team
 * Brief:  window main
 *
 * Copyright (c) 2018 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2019-12-30 Li Peihuang created
 *
 */
#include "awtk.h"
#define IMAGE_TIMER "image_timer_id"

static ret_t on_close(void* ctx, event_t* e) {
  widget_t* win = WIDGET(ctx);
  (void)e;
  value_t v;

  /*移除定时器*/
  if (widget_get_prop(win, IMAGE_TIMER, &v) == RET_OK) {
    timer_remove(value_uint32(&v));
  }

  return window_close(win);
}

ret_t reset_animation(const timer_info_t* timer)
{
  widget_t* widget = timer->ctx;
  widget_create_animator(widget, "rotation(duration=150,yoyo_times=4,easing=linear,from=0,to=0.436)");
  widget_start_animator(NULL,NULL);
  return RET_REPEAT;
}

/**
 * 子控件初始化(主要是设置click回调、初始显示信息)
 */
static ret_t init_widget(void* ctx, const void* iter) {
  widget_t* widget = WIDGET(iter);
  widget_t* win = widget_get_window(widget);
  (void)ctx;
  value_t v;
  
  if (widget->name != NULL) {
    const char* name = widget->name;
    if (tk_str_eq(name, "bt_return")) {
      widget_on(widget, EVT_CLICK, on_close, win);
    } else if (tk_str_eq(name, "image_radar")) {
      widget_create_animator(widget, "rotation(duration=2880,repeat_times=0,easing=linear,from=0,to=6.283185)");
    } else if (tk_str_eq(name, "image_phone")) {
      widget_create_animator(widget, "rotation(duration=150,yoyo_times=4,easing=linear,from=0,to=0.436)");
      
      /*添加定时器 */
      value_set_uint32(&v, timer_add(reset_animation, widget, 1290+150));
      widget_set_prop(win, IMAGE_TIMER, &v);
    } else if (tk_str_eq(name, "svg")) {
        
    }
  }

  return RET_OK;
}

/**
 * 点击创建新饼图或者拱形定时器
 */
// static ret_t on_new_timer(const timer_info_t* timer) {
//   widget_t* win = WIDGET(timer->ctx);

//   uint32_t count = widget_animator_manager_count(widget_animator_manager());
//   if (count == 0) {
//     widget_t* image_shake = widget_lookup(win, "image_shake", TRUE);
//     if (image_shake) {
//       WIDGET_FOR_EACH_CHILD_BEGIN(image_shake, iter, i)
//       char param[100];
//       tk_snprintf(param, sizeof(param),
//                   "rotation(duration=1000,yoyo_times=0,easing=linear,from=0,to=180)");
//       widget_create_animator(image_shake, param);
//       WIDGET_FOR_EACH_CHILD_END();
//     }
//     timer_add(on_save_exploded_timer, win, 1000 / 60);

//     return RET_REMOVE;
//   }

//   return RET_REPEAT;
// }

/**
 * 打开窗口时使用动画展示饼图
 */
// static ret_t on_window_open(void* ctx, event_t* e) {
//   widget_t* open = WIDGET(e->target);

//   if (open != NULL && open->name != NULL) {
//     timer_info_t info;
//     info.ctx = ctx;
//     on_new_timer(&info);
//   }

//   return RET_REMOVE;
// }

/**
 * 初始化窗口上的子控件
 */
static void init_children_widget(widget_t* widget) {
  widget_foreach(widget, init_widget, widget);
}

/**
 * 初始化
 */
ret_t open_finding_window() {
  ret_t ret;
  widget_t* win = window_open("finding/finding");
  if (win) {
    init_children_widget(win);
    // image_shake_create(win, 143, 189, 82, 118);
    // widget_on(win, EVT_WINDOW_OPEN, on_window_open, win);
  }
  
  ret = window_manager_set_show_fps(win, 1);
  return RET_OK;
}