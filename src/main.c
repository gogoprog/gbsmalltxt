#include <gb/gb.h>
#include <stdio.h>
#include <string.h>

typedef UINT8 uint8;
typedef UINT16 uint16;

static const uint8 font_height = 6;
static const uint8 font_width = 3;
static const uint8 font_spacing = 1;
static const uint8 font_offset = 32;

static const uint8 font[] = {
    0x00, 0x00, 0x00, // ' '  32
    0x00, 0x17, 0x00, // '!'  33
    0x03, 0x00, 0x03, // '"'  34
    0x1F, 0x0A, 0x1F, // '#'  35
    0x16, 0x1F, 0x0D, // '$'  36
    0x19, 0x04, 0x13, // '%'  37
    0x1A, 0x15, 0x0A, // '&'  38
    0x00, 0x03, 0x00, // '''  39
    0x0E, 0x11, 0x00, // '('  40
    0x00, 0x11, 0x0E, // ')'  41
    0x0A, 0x04, 0x0A, // '*'  42
    0x04, 0x0E, 0x04, // '+'  43
    0x10, 0x08, 0x00, // ','  44
    0x04, 0x04, 0x04, // '-'  45
    0x00, 0x10, 0x00, // '.'  46
    0x18, 0x04, 0x03, // '/'  47
    0x1F, 0x11, 0x1F, // '0'  48
    0x12, 0x1F, 0x10, // '1'  49
    0x1D, 0x15, 0x17, // '2'  50
    0x11, 0x15, 0x1F, // '3'  51
    0x07, 0x04, 0x1F, // '4'  52
    0x17, 0x15, 0x1D, // '5'  53
    0x1F, 0x15, 0x1D, // '6'  54
    0x19, 0x05, 0x03, // '7'  55
    0x1F, 0x15, 0x1F, // '8'  56
    0x17, 0x15, 0x1F, // '9'  57
    0x00, 0x0A, 0x00, // ':'  58
    0x10, 0x0A, 0x00, // ';'  59
    0x04, 0x0A, 0x11, // '<'  60
    0x0A, 0x0A, 0x0A, // '='  61
    0x11, 0x0A, 0x04, // '>'  62
    0x01, 0x15, 0x03, // '?'  63
    0x0E, 0x11, 0x16, // '@'  64
    0x1F, 0x05, 0x1F, // 'A'  65
    0x1F, 0x15, 0x1B, // 'B'  66
    0x0E, 0x11, 0x11, // 'C'  67
    0x1F, 0x11, 0x0E, // 'D'  68
    0x1F, 0x15, 0x15, // 'E'  69
    0x1F, 0x05, 0x05, // 'F'  70
    0x0E, 0x11, 0x1D, // 'G'  71
    0x1F, 0x04, 0x1F, // 'H'  72
    0x11, 0x1F, 0x11, // 'I'  73
    0x08, 0x11, 0x0F, // 'J'  74
    0x1F, 0x04, 0x1B, // 'K'  75
    0x1F, 0x10, 0x10, // 'L'  76
    0x1F, 0x02, 0x1F, // 'M'  77
    0x1F, 0x01, 0x1E, // 'N'  78
    0x0E, 0x11, 0x0E, // 'O'  79
    0x1F, 0x05, 0x06, // 'P'  80
    0x0E, 0x19, 0x1F, // 'Q'  81
    0x1F, 0x05, 0x1B, // 'R'  82
    0x12, 0x15, 0x09, // 'S'  83
    0x01, 0x1F, 0x01, // 'T'  84
    0x0F, 0x10, 0x1F, // 'U'  85
    0x0F, 0x10, 0x0F, // 'V'  86
    0x1F, 0x0C, 0x1F, // 'W'  87
    0x1B, 0x04, 0x1B, // 'X'  88
    0x03, 0x1C, 0x03, // 'Y'  89
    0x19, 0x15, 0x13, // 'Z'  90
    0x00, 0x1F, 0x11, // '['  91
    0x03, 0x04, 0x18, // '\'  92
    0x11, 0x1F, 0x00, // ']'  93
    0x02, 0x01, 0x02, // '^'  94
    0x10, 0x10, 0x10, // '_'  95
    0x01, 0x02, 0x00, // '`'  96
    0x0C, 0x12, 0x1E, // 'a'  97
    0x1F, 0x12, 0x0C, // 'b'  98
    0x0C, 0x12, 0x12, // 'c'  99
    0x0C, 0x12, 0x1F, // 'd' 100
    0x0C, 0x1A, 0x16, // 'e' 101
    0x1E, 0x09, 0x02, // 'f' 102
    0x24, 0x2A, 0x1E, // 'g' 103
    0x1F, 0x04, 0x18, // 'h' 104
    0x00, 0x1D, 0x00, // 'i' 105
    0x20, 0x20, 0x1D, // 'j' 106
    0x1F, 0x04, 0x1A, // 'k' 107
    0x00, 0x0F, 0x10, // 'l' 108
    0x1E, 0x04, 0x1E, // 'm' 109
    0x1E, 0x02, 0x1C, // 'n' 110
    0x0C, 0x12, 0x0C, // 'o' 111
    0x3E, 0x0A, 0x04, // 'p' 112
    0x04, 0x0A, 0x3E, // 'q' 113
    0x1E, 0x04, 0x02, // 'r' 114
    0x14, 0x16, 0x1A, // 's' 115
    0x02, 0x0F, 0x12, // 't' 116
    0x0E, 0x10, 0x1E, // 'u' 117
    0x0E, 0x10, 0x0E, // 'v' 118
    0x1E, 0x08, 0x1E, // 'w' 119
    0x1A, 0x04, 0x1A, // 'x' 120
    0x26, 0x28, 0x1E, // 'y' 121
    0x1A, 0x1E, 0x16, // 'z' 122
    0x04, 0x1F, 0x11, // '{' 123
    0x00, 0x1F, 0x00, // '|' 124
    0x11, 0x1F, 0x04, // '}' 125
    0x01, 0x03, 0x02, // '~' 126
    0x0E, 0x09, 0x0E  // delete 127
};

struct smalltxt_ctx {
    uint8 tiles[250 * 16];
    uint8 tilemap[1024];
    int width;
    int height;
};

void smalltxt_set_pixel(struct smalltxt_ctx *ctx, const int x, const int y, const uint8 value) {
    int ox = x / 8;
    int dx = x % 8;
    int oy = y / 8;
    int dy = y % 8;
    int width = ctx->width;

    uint8 *tiles = ctx->tiles;

    uint8 l = ((value & 0b10) >> 1) << (7 - dx);
    uint8 u = (value & 0b01) << (7 - dx);

    tiles[oy * width * 16 + dy * 2 + ox * 16 + 0] |= u;
    tiles[oy * width * 16 + dy * 2 + ox * 16 + 1] |= l;
}

void smalltxt_draw_char(struct smalltxt_ctx *ctx, const int x, const int y, const char index) {
    const uint8 *data = font + (index - font_offset) * font_width;

    for (int r = 0; r < font_width; r++) {
        int line_data = data[r];
        for (int c = 0; c < font_height; c++) {
            int v = line_data & (1 << c);
            if (v) {
                smalltxt_set_pixel(ctx, x + r, y + c, 11);
            }
        }
    }
}

void smalltxt_draw_text(struct smalltxt_ctx *ctx, const int x, const int y, const char *text) {
    int len = strlen(text);
    int offset_x = 0;

    for (int i = 0; i < len; i++) {
        smalltxt_draw_char(ctx, x + offset_x, y, text[i]);
        offset_x += font_width;
        offset_x += font_spacing;
    }
}

void smalltxt_init(struct smalltxt_ctx *ctx, const int width, const int height) {
    ctx->width = width;
    ctx->height = height;

    memset(ctx->tiles, 0, 250 * 16);

    /* smalltxt_set_pixel(ctx->tiles, 0, 0, 0b11); */
    /* smalltxt_set_pixel(ctx->tiles, 1, 1, 0b11); */
    /* smalltxt_set_pixel(ctx->tiles, 2, 2, 0b11); */
    /* smalltxt_set_pixel(ctx->tiles, 20, 5, 0b11); */

    smalltxt_draw_char(ctx, 1, 1, 'A');
    smalltxt_draw_char(ctx, 1, 32, 'C');

    smalltxt_draw_text(ctx, 1, 16, "HELLO WORLD");

    memset(ctx->tilemap, 0, 128);

    for (int i = 0; i < 250; i++) {
        ctx->tilemap[i] = i;
    }
}

void smalltxt_render(struct smalltxt_ctx *ctx) {
    set_win_data(0, 64, ctx->tiles);
    set_win_tiles(0, 0, ctx->width, ctx->height, ctx->tilemap);
    SHOW_WIN;
}

void main(void) {
    UINT8 background_tilemap[32 * 32];
    UINT8 tileset[16];

    memset(tileset, 0, 16);
    memset(background_tilemap, 0, 32 * 32);

    set_bkg_data(0, 1, tileset);
    set_bkg_tiles(0, 0, 32, 32, background_tilemap);

    SHOW_BKG;

    struct smalltxt_ctx ctx;
    smalltxt_init(&ctx, 10, 10);

    smalltxt_render(&ctx);
}
