//
//  InkCallbacks.h
//  Ink
//
//  Created by Wess Cope on 5/2/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "markdown.h"
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <JInjector/JInjector.h>
#import "InkStringBuilder.h"

#ifndef Ink_InkCallbacks_h
#define Ink_InkCallbacks_h


static void appendTextWithAttributes(const struct buf *text, NSDictionary *attributes)
{
    NSString *outputString                  = [[NSString alloc] initWithData:[NSData dataWithBytes:text->data length:text->size] encoding:NSUTF8StringEncoding];
    NSMutableAttributedString *attrString   = [[NSMutableAttributedString alloc] initWithString:outputString];

    if(attributes)
        [attrString addAttributes:attributes range:NSMakeRange(0, outputString.length)];

    InkStringBuilder* stringBuilder = JInject(InkStringBuilder);
    [stringBuilder.attributedString appendAttributedString:attrString];
}

static void renderBlockcode(struct buf *ob, const struct buf *text, const struct buf *lang, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderBlockquote(struct buf *ob, const struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderBlockhtml(struct buf *ob,const  struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderHeader(struct buf *ob, const struct buf *text, int level, void *opaque)
{
//    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
//    
//    bufputs(ob, "------------------------------------\n");
//    bufput(ob, text->data, text->size);
//    bufputs(ob, "------------------------------------\n");
//    bufputc(ob, '\n');

    
    level = MAX(MIN(level -1, 5), 0);
    
    CGFloat fontSize = 0.0f;
    switch (level)
    {
        case 0:
            fontSize = 32.0f;
            break;
        case 1:
            fontSize = 18.0f;
        default:
            fontSize = 12.0f;
            break;
    }
    
    struct buf *htext = (struct buf *)text;
    bufputc(htext, '\n');

    appendTextWithAttributes(htext, @{NSForegroundColorAttributeName: [UIColor blueColor], NSFontAttributeName: [UIFont boldSystemFontOfSize:fontSize]});
}

static void renderHrule(struct buf *ob, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderList(struct buf *ob, const struct buf *text, int flags, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderListitem(struct buf *ob, const struct buf *text, int flags, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderParagraph(struct buf *ob, const struct buf *text, void *opaque)
{
//    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
//    
//    bufput(ob, text->data, text->size);
//    bufputc(ob, '\n');
//    bufputc(ob, '\n');

    struct buf *ptext = (struct buf *)text;
    bufputc(ptext, '\n');
    
    appendTextWithAttributes(ptext, @{NSForegroundColorAttributeName: [UIColor redColor]});
}

static void renderTable(struct buf *ob, const struct buf *header, const struct buf *body, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderTableRow(struct buf *ob, const struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderTableCell(struct buf *ob, const struct buf *text, int flags, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}



/* span level callbacks - NULL or return 0 prints the span verbatim */
static int renderAutolink(struct buf *ob, const struct buf *link, enum mkd_autolink type, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderCodespan(struct buf *ob, const struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderDoubleEmphasis(struct buf *ob, const struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderEmphasis(struct buf *ob, const struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderImage(struct buf *ob, const struct buf *link, const struct buf *title, const struct buf *alt, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderLinebreak(struct buf *ob, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderLink(struct buf *ob, const struct buf *link, const struct buf *title, const struct buf *content, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderRawHtmlTag(struct buf *ob, const struct buf *tag, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderTripleEmphasis(struct buf *ob, const struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderStrikethrough(struct buf *ob, const struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}

static int renderSuperscript(struct buf *ob, const struct buf *text, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
    return 1;
}


/* low level callbacks - NULL copies input directly into the output */
static void renderEntity(struct buf *ob, const struct buf *entity, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderNormalText(struct buf *ob, const struct buf *text, void *opaque)
{
    bufput(ob, text->data, text->size);
}


/* header and footer */
static void renderDocHeader(struct buf *ob, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

static void renderDocFooter(struct buf *ob, void *opaque)
{
    NSLog(@"%@\n", [NSString stringWithCString:__func__ encoding:NSUTF8StringEncoding]);
}

struct sd_callbacks inkCallbacks = {
    .blockcode          = renderBlockcode,
    .blockquote         = renderBlockquote,
    .blockhtml          = renderBlockhtml,
    .header             = renderHeader,
    .hrule              = renderHrule,
    .list               = renderList,
    .listitem           = renderListitem,
    .paragraph          = renderParagraph,
    .table              = renderTable,
    .table_row          = renderTableRow,
    .table_cell         = renderTableCell,
    .autolink           = renderAutolink,
    .codespan           = renderCodespan,
    .double_emphasis    = renderDoubleEmphasis,
    .emphasis           = renderEmphasis,
    .image              = renderImage,
    .linebreak          = renderLinebreak,
    .link               = renderLink,
    .raw_html_tag       = renderRawHtmlTag,
    .triple_emphasis    = renderTripleEmphasis,
    .strikethrough      = renderStrikethrough,
    .superscript        = renderSuperscript,
    .entity             = renderEntity,
    .normal_text        = renderNormalText,
    .doc_header         = renderDocHeader,
    .doc_footer         = renderDocFooter,
};

#endif
