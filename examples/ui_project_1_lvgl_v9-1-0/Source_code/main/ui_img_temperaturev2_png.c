// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: ui_demo_lvgl

#include "ui.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
    #define LV_ATTRIBUTE_MEM_ALIGN
#endif

// IMAGE DATA: assets/temperaturev2.png
const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_temperaturev2_png_data[] = {
  0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52, 
  0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x1e, 0x08, 0x06, 0x00, 0x00, 0x00, 0x3b, 0x30, 0xae, 
  0xa2, 0x00, 0x00, 0x00, 0x20, 0x63, 0x48, 0x52, 0x4d, 0x00, 0x00, 0x7a, 0x26, 0x00, 0x00, 0x80, 
  0x84, 0x00, 0x00, 0xfa, 0x00, 0x00, 0x00, 0x80, 0xe8, 0x00, 0x00, 0x75, 0x30, 0x00, 0x00, 0xea, 
  0x60, 0x00, 0x00, 0x3a, 0x98, 0x00, 0x00, 0x17, 0x70, 0x9c, 0xba, 0x51, 0x3c, 0x00, 0x00, 0x00, 
  0x06, 0x62, 0x4b, 0x47, 0x44, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xa0, 0xbd, 0xa7, 0x93, 0x00, 
  0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x0e, 0xc4, 0x00, 0x00, 0x0e, 0xc4, 0x01, 
  0x95, 0x2b, 0x0e, 0x1b, 0x00, 0x00, 0x00, 0x07, 0x74, 0x49, 0x4d, 0x45, 0x07, 0xe8, 0x05, 0x16, 
  0x11, 0x30, 0x39, 0x16, 0xf6, 0xc3, 0xc0, 0x00, 0x00, 0x05, 0x44, 0x49, 0x44, 0x41, 0x54, 0x48, 
  0xc7, 0xad, 0xd7, 0x5b, 0x8c, 0x55, 0x67, 0x19, 0x06, 0xe0, 0xe7, 0x5f, 0x6b, 0xcd, 0x9e, 0x33, 
  0x87, 0x41, 0xb4, 0x2a, 0x22, 0x72, 0x6a, 0x82, 0xb1, 0xd5, 0x44, 0x45, 0x62, 0xa0, 0xd6, 0x0a, 
  0xb6, 0x86, 0x9a, 0x28, 0x43, 0x6c, 0x5a, 0xa5, 0x06, 0x6f, 0x6a, 0x13, 0x8a, 0x1a, 0x2f, 0x4c, 
  0xbc, 0x51, 0x63, 0xaa, 0xb6, 0x36, 0xbd, 0x30, 0x6a, 0x3c, 0xc4, 0x03, 0x98, 0x6a, 0x60, 0x52, 
  0xa3, 0xb5, 0x44, 0xa5, 0xb6, 0xb6, 0xd2, 0x60, 0x5b, 0xa5, 0xd6, 0x88, 0x50, 0x84, 0x42, 0x11, 
  0x3a, 0x03, 0x03, 0x0c, 0x03, 0x7b, 0x98, 0x99, 0x3d, 0x7b, 0xaf, 0xdf, 0x8b, 0xb5, 0x67, 0x98, 
  0x19, 0x46, 0x4a, 0x81, 0x2f, 0xd9, 0xc9, 0xca, 0xda, 0xeb, 0xff, 0xdf, 0x6f, 0x7d, 0xef, 0xfb, 
  0xbd, 0xdf, 0xbf, 0x82, 0x2b, 0x88, 0xc3, 0x07, 0xcb, 0xa3, 0x97, 0xaf, 0xc7, 0x97, 0x71, 0x47, 
  0xcf, 0xb1, 0xfe, 0x99, 0x67, 0xcf, 0x0e, 0x1d, 0x48, 0x92, 0x70, 0x7f, 0x9a, 0x26, 0x3f, 0xcd, 
  0xf3, 0xbc, 0x9a, 0x24, 0x89, 0x15, 0x1f, 0x98, 0x37, 0x61, 0x6d, 0x72, 0x25, 0xc0, 0xf5, 0x68, 
  0xc6, 0xbd, 0xb8, 0x27, 0xcd, 0xc2, 0xac, 0xe6, 0xa6, 0x2c, 0xc9, 0xd2, 0x64, 0x51, 0x8c, 0xf1, 
  0x81, 0x5a, 0x2d, 0xff, 0x64, 0x75, 0xa4, 0x26, 0x49, 0xc2, 0x05, 0x8b, 0xb2, 0xab, 0x00, 0xbc, 
  0x1c, 0xb7, 0x97, 0x1a, 0x83, 0x69, 0xd3, 0x53, 0x59, 0xd6, 0xa6, 0xa1, 0xa1, 0xc1, 0xf1, 0xde, 
  0xfe, 0xf6, 0x6a, 0x35, 0xdf, 0x98, 0x35, 0xa4, 0x8f, 0x26, 0x69, 0xd2, 0xbb, 0x72, 0xf9, 0x57, 
  0x27, 0x02, 0xaf, 0xeb, 0xec, 0x9a, 0x62, 0xaf, 0x68, 0x53, 0xd7, 0xda, 0x4b, 0x05, 0xbe, 0x0e, 
  0xcd, 0xcd, 0x2d, 0x89, 0x34, 0x0b, 0x42, 0x08, 0x5a, 0x5a, 0x4a, 0x9a, 0x9b, 0x4b, 0xce, 0x9c, 
  0x19, 0x9a, 0x17, 0x63, 0x9c, 0xb3, 0xeb, 0xb9, 0x7d, 0xbd, 0x58, 0x8c, 0x8f, 0xa1, 0x84, 0xa3, 
  0xe3, 0x4b, 0x3d, 0xee, 0x3a, 0x98, 0x3a, 0xa1, 0x29, 0xa3, 0x04, 0x61, 0x52, 0x35, 0x43, 0x71, 
  0x23, 0x89, 0x51, 0x76, 0xfc, 0x58, 0x1f, 0x7c, 0xa8, 0x4e, 0xc9, 0xd7, 0x70, 0x6f, 0x86, 0x99, 
  0xb8, 0xb3, 0x5e, 0xb2, 0x97, 0xf0, 0x03, 0xec, 0xbf, 0x0a, 0x14, 0x8c, 0xc5, 0xc2, 0xc5, 0x73, 
  0xec, 0xdc, 0xb1, 0x7b, 0x0b, 0x0e, 0xd4, 0x13, 0x3d, 0x91, 0xe1, 0x3e, 0xac, 0xc7, 0x39, 0xb4, 
  0xe1, 0x9d, 0xb8, 0x0d, 0x27, 0xaf, 0x16, 0xf0, 0xeb, 0x66, 0x4f, 0x87, 0x3e, 0xfc, 0x1d, 0xc3, 
  0x38, 0x9b, 0x61, 0x1d, 0xf6, 0xd6, 0xc1, 0x3f, 0x87, 0x4e, 0x5c, 0x8f, 0xc7, 0x2f, 0x56, 0xee, 
  0xe0, 0xd2, 0xe3, 0x6f, 0xcf, 0xec, 0x85, 0xb5, 0xf8, 0x46, 0xbd, 0xaa, 0xeb, 0x33, 0x0c, 0xa1, 
  0x05, 0xf3, 0xd1, 0x81, 0x2a, 0x2a, 0xf5, 0x35, 0x8d, 0x78, 0x2b, 0xae, 0xc1, 0x08, 0x8e, 0xe0, 
  0x28, 0xf2, 0xf8, 0x1a, 0x80, 0x1b, 0x4a, 0x19, 0x9c, 0xaa, 0x83, 0xbe, 0x8c, 0xe1, 0x04, 0x0f, 
  0x60, 0x36, 0x1e, 0xc2, 0x2a, 0x6c, 0xc1, 0x3f, 0x70, 0x13, 0x7e, 0x85, 0xbf, 0x60, 0x3b, 0x1e, 
  0xc7, 0x53, 0xf8, 0x8e, 0x42, 0xa1, 0x97, 0x1c, 0x4b, 0x97, 0x2d, 0x81, 0x3f, 0x62, 0x95, 0x24, 
  0xae, 0x47, 0x4f, 0x86, 0x6f, 0x61, 0x17, 0xde, 0x87, 0x83, 0xf8, 0x0d, 0xee, 0xc0, 0x37, 0x15, 
  0xe6, 0xb0, 0x03, 0xbb, 0xd1, 0x84, 0xf7, 0xe0, 0x6e, 0xd4, 0x70, 0x4f, 0x9e, 0xc7, 0x29, 0xcd, 
  0x61, 0x72, 0xbc, 0xb8, 0xe7, 0x30, 0x2c, 0xc0, 0x6a, 0x79, 0x28, 0xe1, 0x95, 0xac, 0x4e, 0xf6, 
  0xef, 0xea, 0x3f, 0xb8, 0x59, 0x21, 0xb8, 0x93, 0x0a, 0xde, 0x7f, 0x8f, 0xc1, 0xfa, 0x7f, 0xb3, 
  0x15, 0x6d, 0xb1, 0x0f, 0x97, 0x04, 0x0a, 0xdd, 0x47, 0x4f, 0x8e, 0xee, 0xfb, 0xa0, 0x42, 0x1e, 
  0xc7, 0x27, 0x3b, 0x57, 0x8b, 0x42, 0x60, 0x19, 0x36, 0xe2, 0x11, 0x08, 0x39, 0xb1, 0xe8, 0xf2, 
  0x5e, 0xfc, 0xf2, 0xa2, 0x28, 0x53, 0xe4, 0x32, 0x7f, 0xd1, 0x9b, 0xed, 0x7c, 0x7a, 0xf7, 0x56, 
  0xfc, 0x57, 0xd1, 0x4e, 0xc7, 0xb3, 0x4d, 0x5d, 0x9d, 0x30, 0x6a, 0x18, 0x8b, 0xeb, 0x25, 0x7f, 
  0x0c, 0x7f, 0x18, 0x5d, 0xf8, 0xf3, 0x87, 0x3b, 0xa7, 0xc4, 0xf8, 0xfa, 0xfd, 0xe5, 0x89, 0x88, 
  0x79, 0x4d, 0x18, 0x1c, 0x24, 0x36, 0x4e, 0x78, 0xee, 0x9a, 0x37, 0xce, 0x84, 0x13, 0x0a, 0x8d, 
  0x54, 0x70, 0x6e, 0xf2, 0x90, 0x98, 0x83, 0x69, 0x78, 0xbe, 0xfe, 0x80, 0xd1, 0xc4, 0x5e, 0x35, 
  0x42, 0x90, 0xfe, 0x7b, 0x87, 0x69, 0x3f, 0x7a, 0x50, 0xd6, 0x73, 0x6c, 0x82, 0x95, 0x3d, 0xf7, 
  0xd7, 0xbd, 0xb0, 0x06, 0xcf, 0xe0, 0x61, 0xcc, 0x9d, 0x0c, 0x9c, 0x23, 0xba, 0xcc, 0xe1, 0x11, 
  0x7a, 0x0e, 0x68, 0xd8, 0xff, 0xa2, 0xac, 0xef, 0xf4, 0x04, 0xe0, 0x34, 0x4b, 0x61, 0xa0, 0x4e, 
  0x55, 0x2f, 0x46, 0x26, 0x03, 0x1c, 0xc6, 0x69, 0xbc, 0x57, 0xa1, 0xe8, 0xc1, 0x75, 0x9d, 0x5d, 
  0x36, 0x75, 0x75, 0x5a, 0xb7, 0xb6, 0xab, 0x48, 0xe9, 0x55, 0xde, 0x5a, 0x72, 0xe1, 0xa4, 0x5d, 
  0xba, 0x6c, 0x89, 0x27, 0xb6, 0xef, 0xda, 0xa6, 0x68, 0xcb, 0x2a, 0xe2, 0x64, 0xe0, 0xff, 0xe0, 
  0xcf, 0xb8, 0x55, 0xe1, 0x60, 0x9b, 0xa9, 0xf3, 0x7f, 0x1e, 0x74, 0x16, 0x66, 0xe0, 0xa5, 0x5a, 
  0x2d, 0x8f, 0x69, 0x7a, 0xd1, 0x91, 0x1e, 0x11, 0xf7, 0xef, 0x3b, 0x02, 0xf3, 0x14, 0xca, 0x2e, 
  0xa1, 0x7b, 0x32, 0xf0, 0xb0, 0x42, 0xf2, 0xef, 0x57, 0x18, 0x4b, 0x2b, 0xba, 0x14, 0xae, 0x93, 
  0x60, 0x89, 0xa2, 0xbf, 0xdf, 0x80, 0xd5, 0x87, 0x0f, 0x9d, 0xee, 0x7e, 0xdb, 0x82, 0x8e, 0x8b, 
  0xd1, 0x92, 0x20, 0x3d, 0x79, 0xa2, 0x1f, 0x56, 0x2b, 0xcc, 0x07, 0x7a, 0xc7, 0xd2, 0x1d, 0x57, 
  0xc5, 0x1d, 0xd8, 0x50, 0x4f, 0xe2, 0x7b, 0x0a, 0xc7, 0xda, 0x82, 0x5f, 0x2b, 0x94, 0x7e, 0x0b, 
  0x9e, 0x7d, 0xe1, 0xf9, 0x57, 0x4e, 0x2d, 0x58, 0x34, 0xeb, 0x7a, 0xac, 0x09, 0xc1, 0x05, 0x73, 
  0x31, 0x14, 0x3d, 0xde, 0x8e, 0xcf, 0xae, 0xbc, 0xf9, 0xdd, 0xd3, 0x2a, 0xc3, 0x23, 0x5d, 0xf8, 
  0x04, 0x3e, 0x85, 0xdb, 0xc7, 0x80, 0x37, 0x4f, 0x54, 0xef, 0x56, 0x7c, 0x54, 0x31, 0x22, 0x4b, 
  0xf8, 0xa0, 0xa2, 0xcd, 0x0e, 0x61, 0xc3, 0x99, 0xfe, 0xa1, 0x2f, 0x3e, 0xbe, 0xf3, 0xae, 0xe6, 
  0x3c, 0x8f, 0xdf, 0x0e, 0xc1, 0x75, 0x2d, 0x6d, 0x89, 0x52, 0x63, 0x22, 0xd6, 0x9b, 0x38, 0x26, 
  0x89, 0x19, 0x33, 0x5a, 0xb5, 0xb5, 0x36, 0xc2, 0x9d, 0xe5, 0xf2, 0xe0, 0xc6, 0xb6, 0xf6, 0x96, 
  0x9e, 0x2c, 0x4b, 0xb7, 0xe0, 0x17, 0x78, 0xec, 0x82, 0x76, 0x9f, 0x34, 0x91, 0x82, 0xe2, 0x20, 
  0xd7, 0xa1, 0xb0, 0xc9, 0x1e, 0x9c, 0xb9, 0x6b, 0xc3, 0x32, 0x73, 0xe6, 0x4e, 0x5f, 0x87, 0x9f, 
  0x34, 0xb7, 0x24, 0x69, 0xfb, 0x8c, 0x4c, 0x72, 0xfc, 0xa0, 0x6c, 0xdb, 0xf7, 0x85, 0x3f, 0x1d, 
  0x51, 0x7e, 0xc7, 0x2d, 0xfa, 0x3f, 0x7e, 0xab, 0xe1, 0x52, 0x93, 0xee, 0xee, 0x3e, 0x95, 0x4a, 
  0xf5, 0x50, 0x08, 0x61, 0x25, 0xf6, 0xdf, 0x78, 0xd3, 0xfc, 0x31, 0x0e, 0x26, 0xc4, 0xa6, 0xae, 
  0xce, 0xb1, 0xcc, 0xeb, 0x0c, 0x1c, 0xc3, 0x1e, 0x85, 0x4d, 0x9e, 0xf9, 0xc2, 0x97, 0x56, 0x98, 
  0x33, 0x77, 0x7a, 0x82, 0x95, 0x21, 0x48, 0x9b, 0x5b, 0x53, 0x49, 0xf9, 0x94, 0xec, 0xd1, 0xef, 
  0x0a, 0x87, 0x77, 0x13, 0x69, 0xdb, 0xfe, 0x84, 0x69, 0x8f, 0x6c, 0x53, 0x4a, 0x83, 0xb6, 0xb6, 
  0x26, 0x98, 0x8b, 0xa5, 0x31, 0x9e, 0x27, 0x74, 0x4a, 0x61, 0x6c, 0xee, 0x5a, 0xf3, 0x7f, 0xd5, 
  0x52, 0x77, 0xab, 0x46, 0xbc, 0x25, 0x49, 0x83, 0x34, 0x4b, 0x84, 0x97, 0x0f, 0x08, 0xdd, 0xfb, 
  0x8b, 0x56, 0x0a, 0x81, 0x18, 0x35, 0xfd, 0xf3, 0x5f, 0xce, 0x7e, 0xe4, 0xc3, 0x4a, 0x8d, 0x25, 
  0x48, 0x62, 0x8c, 0x73, 0xc7, 0xe1, 0x5e, 0xf6, 0xf1, 0x36, 0x62, 0x44, 0xac, 0x8b, 0xb2, 0xa1, 
  0x89, 0x34, 0x63, 0x74, 0xe7, 0x18, 0xc5, 0xc6, 0x46, 0xb2, 0x6c, 0xec, 0x56, 0x08, 0x46, 0xc6, 
  0xfb, 0xf8, 0xe5, 0x02, 0x0f, 0x61, 0x4f, 0x9e, 0x47, 0xd5, 0xe1, 0x9a, 0xf8, 0xa6, 0x85, 0xf2, 
  0x25, 0xcb, 0x49, 0x52, 0xf2, 0x9a, 0xbc, 0xbd, 0x55, 0xf9, 0xc6, 0x15, 0x6a, 0x2d, 0x2d, 0x86, 
  0x06, 0x2b, 0x50, 0x21, 0xec, 0x19, 0x2f, 0xa8, 0x2b, 0x39, 0x57, 0xff, 0x36, 0x46, 0x9f, 0x3e, 
  0x57, 0xae, 0xb5, 0x37, 0x74, 0x34, 0xb1, 0xea, 0x33, 0xf2, 0xf9, 0xef, 0x32, 0x7c, 0x6d, 0x9f, 
  0x81, 0x8e, 0x05, 0x2a, 0xd7, 0x2e, 0x74, 0xee, 0xdc, 0xb0, 0x72, 0x79, 0x08, 0x5e, 0x08, 0xc1, 
  0xb3, 0x61, 0x5c, 0xcb, 0xbd, 0x66, 0xe0, 0x10, 0x89, 0xc5, 0xfa, 0x27, 0xf1, 0xb3, 0x4a, 0x25, 
  0x6e, 0xe8, 0xef, 0xab, 0x6a, 0x6d, 0x6f, 0xd1, 0xf0, 0xf6, 0x1b, 0x0c, 0xcc, 0xa9, 0x19, 0x28, 
  0x57, 0x0d, 0x96, 0x87, 0x9c, 0xea, 0x2b, 0xab, 0xd5, 0xf2, 0xb3, 0x21, 0x84, 0xfb, 0x6a, 0xb5, 
  0xbc, 0xf7, 0xc9, 0xa7, 0xf6, 0x9c, 0xdf, 0xe7, 0x72, 0x5e, 0x75, 0xdc, 0x37, 0x53, 0x87, 0xe2, 
  0xac, 0xbc, 0x2e, 0x24, 0x9a, 0xb3, 0x34, 0x38, 0x71, 0x72, 0x40, 0xff, 0xe9, 0x41, 0x23, 0xd5, 
  0xaa, 0x18, 0x75, 0x87, 0x10, 0xbe, 0xd2, 0xd0, 0x90, 0xfe, 0xb8, 0x56, 0xcb, 0xf3, 0x90, 0x04, 
  0x2b, 0x6e, 0x98, 0x77, 0xf9, 0x1c, 0xe7, 0xe7, 0x2f, 0x4f, 0xe1, 0xf3, 0xb8, 0x3b, 0xe6, 0x9e, 
  0xae, 0x54, 0xe2, 0xc0, 0xe0, 0xe0, 0x48, 0x1c, 0xae, 0x8c, 0x9c, 0x88, 0xd1, 0xd6, 0x10, 0xc2, 
  0x6d, 0x3b, 0x76, 0xee, 0xfd, 0x61, 0xb5, 0x5a, 0xcb, 0x63, 0x8c, 0x63, 0xa0, 0xf0, 0x3f, 0xad, 
  0x41, 0xd8, 0xe2, 0xe2, 0x40, 0x81, 0x6a, 0x00, 0x00, 0x00, 0x25, 0x74, 0x45, 0x58, 0x74, 0x64, 
  0x61, 0x74, 0x65, 0x3a, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x00, 0x32, 0x30, 0x32, 0x34, 0x2d, 
  0x30, 0x35, 0x2d, 0x32, 0x32, 0x54, 0x31, 0x37, 0x3a, 0x34, 0x38, 0x3a, 0x35, 0x36, 0x2b, 0x30, 
  0x30, 0x3a, 0x30, 0x30, 0x55, 0x69, 0x22, 0xea, 0x00, 0x00, 0x00, 0x25, 0x74, 0x45, 0x58, 0x74, 
  0x64, 0x61, 0x74, 0x65, 0x3a, 0x6d, 0x6f, 0x64, 0x69, 0x66, 0x79, 0x00, 0x32, 0x30, 0x32, 0x34, 
  0x2d, 0x30, 0x35, 0x2d, 0x32, 0x32, 0x54, 0x31, 0x37, 0x3a, 0x34, 0x38, 0x3a, 0x35, 0x36, 0x2b, 
  0x30, 0x30, 0x3a, 0x30, 0x30, 0x24, 0x34, 0x9a, 0x56, 0x00, 0x00, 0x00, 0x28, 0x74, 0x45, 0x58, 
  0x74, 0x64, 0x61, 0x74, 0x65, 0x3a, 0x74, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x00, 
  0x32, 0x30, 0x32, 0x34, 0x2d, 0x30, 0x35, 0x2d, 0x32, 0x32, 0x54, 0x31, 0x37, 0x3a, 0x34, 0x38, 
  0x3a, 0x35, 0x37, 0x2b, 0x30, 0x30, 0x3a, 0x30, 0x30, 0xd5, 0x56, 0xb0, 0x3d, 0x00, 0x00, 0x00, 
  0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6f, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x00, 0x77, 0x77, 
  0x77, 0x2e, 0x69, 0x6e, 0x6b, 0x73, 0x63, 0x61, 0x70, 0x65, 0x2e, 0x6f, 0x72, 0x67, 0x9b, 0xee, 
  0x3c, 0x1a, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};
const lv_img_dsc_t ui_img_temperaturev2_png = {
    // .header.always_zero = 0,
    .header.w = 30,
    .header.h = 30,
    .data_size = sizeof(ui_img_temperaturev2_png_data),
    .header.cf = LV_COLOR_FORMAT_RAW_ALPHA,
    .data = ui_img_temperaturev2_png_data
};
