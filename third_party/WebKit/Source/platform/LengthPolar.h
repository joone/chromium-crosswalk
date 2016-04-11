// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef LengthPolar_h
#define LengthPolar_h

#include "platform/Length.h"
#include "wtf/Allocator.h"

namespace blink {

struct LengthPolar {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
public:
    LengthPolar(const float angle, const Length& distance, const Length& origin_x, const Length& origin_y, const Length& anchor_x, const Length& anchor_y)
        : m_angle(angle)
        , m_distance(distance)
        , m_origin_x(origin_x)
        , m_origin_y(origin_y)
        , m_anchor_x(anchor_x)
        , m_anchor_y(anchor_y)
        , m_hasPolar(false)
    {
    }

    bool operator==(const LengthPolar& o) const { return m_angle == o.m_angle && m_distance == o.m_distance; }
    bool operator!=(const LengthPolar& o) const { return m_angle != o.m_angle || m_distance != o.m_distance; }

    void setAngle(float angle) { m_angle = angle; }
    float angle() const { return m_angle; }

    void setDistance(const Length& distance) { m_distance = distance; }
    const Length& distance() const { return m_distance; }

    void setAnchorX(const Length& anchor_x) { m_anchor_x = anchor_x; }
    const Length& anchorX() const { return m_anchor_x; }

    void setAnchorY(const Length& anchor_y) { m_anchor_y = anchor_y; }
    const Length& anchorY() const { return m_anchor_y; }

    void setOriginX(const Length& origin_x) { m_origin_x = origin_x; }
    const Length& originX() const { return m_origin_x; }

    void setOriginY(const Length& origin_y) { m_origin_y = origin_y; }
    const Length& originY() const { return m_origin_y; }

    bool hasPolar() const { return m_hasPolar; }

    // Must be public for SET_VAR in ComputedStyle.h
    float m_angle;
    Length m_distance;
    Length m_origin_x;
    Length m_origin_y;
    Length m_anchor_x;
    Length m_anchor_y;
    bool m_hasPolar;
};

} // namespace blink

#endif // LengthPolar_h
