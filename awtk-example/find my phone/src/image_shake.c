/**
 * File:   image_shake.c
 * Author: AWTK Develop Team
 * Brief:  image_shake
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
 * 2018-04-05 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "awtk.h"
#include "image_shake.h"
#include <math.h>


static ret_t image_shake_on_paint_self(widget_t* widget, canvas_t* c) {
  bitmap_t img;
  style_t* style = widget->astyle;
  color_t trans = color_init(0, 0, 0, 0);
  vgcanvas_t* vg = canvas_get_vgcanvas(c);
//   pie_slice_t* pie_slice = PIE_SLICE(widget);
  color_t color = style_get_color(style, STYLE_ID_FG_COLOR, trans);
  const char* image_name = "im_blue_rect";//style_get_str(style, "im_blue_rect", NULL);
  bool_t has_image = image_name && widget_load_image(widget, image_name, &img) == RET_OK;

    image_manager_get_bitmap(image_manager(), "im_blue_rect", &img);
//   if (pie_slice->value > pie_slice->max) {
//     pie_slice->value = pie_slice->max;
//   }

  if (vg != NULL && (has_image || color.rgba.a)) {
    // xy_t cx = widget->w / 2;
    // xy_t cy = widget->h / 2;
    // float_t end_angle = 0;
    // float_t r = 0;
    // bool_t ccw = pie_slice->counter_clock_wise;
    // float_t start_angle = TK_D2R(pie_slice->start_angle);
    // float_t angle = (M_PI * 2 * pie_slice->value) / pie_slice->max;

    // if (ccw) {
    //   end_angle = start_angle - angle + M_PI * 2;
    // } else {
    //   end_angle = start_angle + angle;
    // }

    vgcanvas_save(vg);
    vgcanvas_rotate(vg, 1);
    vgcanvas_set_antialias(vg,TRUE);
    // vgcanvas_draw_icon(vg, &img, widget->x, widget->y, widget->w, widget->h, widget->x, widget->y, widget->w, widget->h);
    // vgcanvas_draw_icon(vg, &img, 0, 0, widget->w, widget->h, widget->x, widget->y, widget->w, widget->h);
    // vgcanvas_rotate(vg, 1);
    vgcanvas_draw_icon(vg, &img, 0, 0, widget->w, widget->h, widget->x, widget->y, widget->w, widget->h);
    // vgcanvas_translate(vg, c->ox, c->oy);
    // if (end_angle > start_angle) {
    //   vgcanvas_set_fill_color(vg, color);
    //   vgcanvas_begin_path(vg);
    //   r = tk_min(cx, cy);
    //   r -= pie_slice->explode_distancefactor;

    //   if (pie_slice->is_semicircle) {
    //     if (ccw) {
    //       start_angle = M_PI * 2 - (start_angle + angle) / 2;
    //       end_angle = start_angle + angle / 2;
    //       cy = cy + r * 0.5;
    //       r += pie_slice->explode_distancefactor * 1.5;
    //       vgcanvas_arc(vg, cx, cy, r, start_angle, end_angle, !ccw);
    //       r -= pie_slice->inner_radius;
    //       vgcanvas_arc(vg, cx, cy, r, end_angle, start_angle, ccw);
    //     }
    //   } else {
    //     vgcanvas_arc(vg, cx, cy, r, start_angle, end_angle, ccw);
    //     if (r - pie_slice->inner_radius <= 0) {
    //       vgcanvas_line_to(vg, cx, cy);
    //     } else {
    //       r -= pie_slice->inner_radius;
    //       vgcanvas_arc(vg, cx, cy, r, end_angle, start_angle, !ccw);
    //     }
    //   }

    //   vgcanvas_close_path(vg);
      if (has_image) {
        // vgcanvas_paint(vg, FALSE, &img);
      } else {
        //vgcanvas_fill(vg);
      }
    // }
    vgcanvas_restore(vg);
  }

  color = style_get_color(style, STYLE_ID_TEXT_COLOR, trans);
//   if (pie_slice->show_text && color.rgba.a) {
//     char s[TK_NUM_MAX_LEN + TK_NUM_MAX_LEN + 1];
//     const char* unit = pie_slice->unit != NULL ? pie_slice->unit : "";
//     tk_snprintf(s, sizeof(s), "%u%s", (uint32_t)(pie_slice->value), unit);

//     widget_set_text_utf8(widget, s);
//     widget_paint_helper(widget, c, NULL, NULL);
//   }
  return RET_OK;
}

ret_t image_shake_set_shake_angle(widget_t* widget, int32_t shake_angle) {
  image_shake_t* image_shake = IMAGE_SHAKE(widget);
  return_value_if_fail(image_shake != NULL, RET_BAD_PARAMS);

  image_shake->shake_angle = shake_angle;

  return widget_invalidate(widget, NULL);
}

ret_t image_shake_set_counter_clock_wise(widget_t* widget, bool_t counter_clock_wise) {
  image_shake_t* image_shake = IMAGE_SHAKE(widget);
  return_value_if_fail(image_shake != NULL, RET_BAD_PARAMS);

  image_shake->counter_clock_wise = counter_clock_wise;

  return widget_invalidate(widget, NULL);
}

ret_t image_shake_set_shake_back(widget_t* widget, bool_t shake_back) {
  image_shake_t* image_shake = IMAGE_SHAKE(widget);
  return_value_if_fail(image_shake != NULL, RET_BAD_PARAMS);

  image_shake->counter_clock_wise = shake_back;

  return widget_invalidate(widget, NULL);
}

ret_t image_shake_set_shake_times(widget_t* widget, int32_t shake_times) {
  image_shake_t* image_shake = IMAGE_SHAKE(widget);
  return_value_if_fail(image_shake != NULL, RET_BAD_PARAMS);

  image_shake->shake_times = shake_times;

  return widget_invalidate(widget, NULL);
}

ret_t image_shake_set_interval_time(widget_t* widget, int32_t interval_time) {
  image_shake_t* image_shake = IMAGE_SHAKE(widget);
  return_value_if_fail(image_shake != NULL, RET_BAD_PARAMS);

  image_shake->interval_time = interval_time;

  return widget_invalidate(widget, NULL);
}

static ret_t image_shake_get_prop(widget_t* widget, const char* name, value_t* v) {
  image_shake_t* image_shake = IMAGE_SHAKE(widget);
  return_value_if_fail(image_shake != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(name, IMAGE_SHAKE_PROP_SHAKE_BACK)) {
    value_set_bool(v, image_shake->shake_back);
    return RET_OK;
  } else if (tk_str_eq(name, IMAGE_SHAKE_PROP_SHAKE_TIMES)) {
    value_set_int32(v, image_shake->shake_times);
    return RET_OK;
  } else if (tk_str_eq(name, IMAGE_SHAKE_PROP_INTERVAL_TIME)) {
    value_set_int32(v, image_shake->interval_time);
    return RET_OK;
  } else if (tk_str_eq(name, IMAGE_SHAKE_PROP_SHAKE_ANGLE)) {
    value_set_int32(v, image_shake->shake_angle);
    return RET_OK;
  }else if (tk_str_eq(name, IMAGE_SHAKE_PROP_COUNTER_CLOCK_WISE)) {
    value_set_bool(v, image_shake->counter_clock_wise);
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t image_shake_set_prop(widget_t* widget, const char* name, const value_t* v) {
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(name, IMAGE_SHAKE_PROP_COUNTER_CLOCK_WISE)) {
    return image_shake_set_counter_clock_wise(widget, value_bool(v));
  } else if (tk_str_eq(name, IMAGE_SHAKE_PROP_SHAKE_ANGLE)) {
    return image_shake_set_shake_angle(widget, value_int(v));
  } else if (tk_str_eq(name, IMAGE_SHAKE_PROP_SHAKE_BACK)) {
    return image_shake_set_shake_back(widget, value_bool(v));
  } else if (tk_str_eq(name, IMAGE_SHAKE_PROP_SHAKE_TIMES)) {
    return image_shake_set_shake_times(widget, value_int(v));
  } else if (tk_str_eq(name, IMAGE_SHAKE_PROP_INTERVAL_TIME)) {
    return image_shake_set_interval_time(widget, value_int(v));
  } 

  return RET_NOT_FOUND;
}

static ret_t on_timer(const timer_info_t* timer){
    widget_t* ctx = (widget_t*)timer->ctx;
    // char param[100];
    // widget_t* image_shake = widget_lookup(win, "image_shake", TRUE);

    // if (image_shake) {
    //   WIDGET_FOR_EACH_CHILD_BEGIN(image_shake, iter, i)
      char param[100];
      tk_snprintf(param, sizeof(param),
                  "rotation(duration=1000,yoyo_times=0,easing=linear,from=0,to=180)");
      widget_create_animator(ctx, param);
    //   WIDGET_FOR_EACH_CHILD_END();
    // }
    widget_start_animator(ctx, NULL);

    return RET_REPEAT;
}

static const char* s_image_shake_clone_properties[] = {WIDGET_PROP_VALUE,
                                                     WIDGET_PROP_MAX,
                                                     IMAGE_SHAKE_PROP_SHAKE_BACK,
                                                     IMAGE_SHAKE_PROP_SHAKE_TIMES,
                                                     IMAGE_SHAKE_PROP_INTERVAL_TIME,
                                                     IMAGE_SHAKE_PROP_SHAKE_ANGLE,
                                                     IMAGE_SHAKE_PROP_COUNTER_CLOCK_WISE,
                                                     WIDGET_PROP_SHOW_TEXT,
                                                     NULL};
static const widget_vtable_t s_image_shake_vtable = {.size = sizeof(image_shake_t),
                                                   .type = WIDGET_TYPE_IMAGE_SHAKE,
                                                   .clone_properties = s_image_shake_clone_properties,
                                                   .create = image_shake_create,
                                                   .on_paint_self = image_shake_on_paint_self,
                                                   .get_prop = image_shake_get_prop,
                                                   .set_prop = image_shake_set_prop};

widget_t* image_shake_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  image_shake_t* image_shake = TKMEM_ZALLOC(image_shake_t);
  widget_t* widget = WIDGET(image_shake);
  return_value_if_fail(image_shake != NULL, NULL);

  widget_init(widget, parent, &s_image_shake_vtable, x, y, w, h);

  image_shake->counter_clock_wise = TRUE;
  image_shake->interval_time = 1000;
  image_shake->shake_angle = 45;
  image_shake->shake_back = TRUE;
  image_shake->shake_times = 2;
  
  timer_add(on_timer, widget, 2500);
  return widget;  
  
}

