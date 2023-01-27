#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstdio>
#include <cstdint>
#include "Definitions.hpp"

const std::int16_t COLOR_TYPE_INDEX = 0; // インデックスカラー方式
const std::int16_t COLOR_TYPE_GRAY  = 1; // グレースケール方式
const std::int16_t COLOR_TYPE_RGB   = 2; // RGB方式
const std::int16_t COLOR_TYPE_RGBA  = 3; // RGBA方式

/**
 * @brief 色情報
 *
 * RGBAの色情報を保持する構造体
 */
using color_t = struct
{
    std::uint8_t r; // Red
    std::uint8_t g; // Green
    std::uint8_t b; // Blue
    std::uint8_t a; // Alpha
};

/**
 * @brief 画素情報
 *
 * 共用体になっており、RGBA値、グレースケール、カラーインデックスの
 * いずれかを表現する。単体ではどの表現形式になっているかを判断する
 * 事はできない
 */
using pixcel_t = union
{
    color_t c; // RGBA
    std::uint8_t g; // グレースケール
    std::uint8_t i; // カラーインデックス
};

/**
 * @brief 画像データ保持の構造体
 *
 * 画像データとして保持するために必要最小限の


#endif // IMAGE_HPP
