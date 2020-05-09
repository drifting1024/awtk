/**
 * File:   image_shake.h
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

#ifndef TK_IMAGE_SHAKE_H
#define TK_IMAGE_SHAKE_H

#include "awtk.h"

BEGIN_C_DECLS


/**
 * @class image_shake_t
 * @parent widget_t
 * @annotation ["scriptable"]
 * image_shake控件。
 */
typedef struct _image_shake_t {
  widget_t widget;
  /**image_shake
   * @property {float_t} shake_back
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 是否需要摇晃回来(缺省为TRUE)。
   */
  bool_t shake_back;
  /**
   * @property {uint32_t} shake_times
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 一次完整的摇晃动作需要来回摇晃几次
   */
  int32_t shake_times;
  /**
   * @property {uint32_t} interval_timel
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 完成摇晃动作后中间的间隔时长
   */
  int32_t interval_time;
  /**
   * @property {int32_t} shake_angle
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 摇晃角度(单位为度，缺省0)。
   */
  int32_t shake_angle;
  /**
   * @property {bool_t} counter_clock_wise
   * @annotation ["set_prop","get_prop","readable","persitent","design","scriptable"]
   * 是否为逆时针方向(缺省为FALSE)。
   */
  bool_t counter_clock_wise;
} image_shake_t;

/**
 * @method image_shake_create
 * @annotation ["constructor", "scriptable"]
 * 创建image_shakee对象
 * @param {widget_t*} parent 父控件
 * @param {xy_t} x x坐标
 * @param {xy_t} y y坐标
 * @param {wh_t} w 宽度
 * @param {wh_t} h 高度
 *
 * @return {widget_t*} 对象。
 */
widget_t* image_shake_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h);


#define WIDGET_TYPE_IMAGE_SHAKE "image_shake"
#define IMAGE_SHAKE(widget) ((image_shake_t*)(widget))

#define IMAGE_SHAKE_PROP_SHAKE_BACK "shake_back"
#define IMAGE_SHAKE_PROP_SHAKE_TIMES "shake_times"
#define IMAGE_SHAKE_PROP_INTERVAL_TIME "interval_time"
#define IMAGE_SHAKE_PROP_SHAKE_ANGLE "shake_angle"
#define IMAGE_SHAKE_PROP_COUNTER_CLOCK_WISE "counter_clock_wise"


END_C_DECLS

#endif /*TK_IMAGE_SHAKE_H*/
