//
//  InkMarkdownRenderer.m
//  Ink
//
//  Created by Wess Cope on 5/2/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "InkMarkdownRenderer.h"
#import "markdown.h"
#import "buffer.h"
#import "InkCallbacks.h"
#import "InkStringBuilder.h"

struct ink_renderopt
{
    unsigned int flags;
};

@interface InkMarkdownRenderer()
@property (strong, nonatomic) InkStringBuilder *stringBuilder;
@end

@implementation InkMarkdownRenderer
@synthesize stringBuilder = _stringBuilder;


- (InkStringBuilder *)stringBuilder
{
    if(_stringBuilder)
        return _stringBuilder;
    
    _stringBuilder = [[InkStringBuilder alloc] init];
    
    return _stringBuilder;
}

- (NSAttributedString *)renderFromString:(NSString *)string
{
    NSData *data                    = [string dataUsingEncoding:NSUTF8StringEncoding];
    struct buf *const inputBuffer   = bufnew(data.length);

    bufput(inputBuffer, data.bytes, data.length);
    
    size_t outputSize               = lround(((double)inputBuffer->size) * 1.2);
    struct buf *const outputBuffer  = bufnew(outputSize);
    unsigned int extensions = 0;

    struct sd_markdown *markdown = sd_markdown_new(extensions, 16, &inkCallbacks, (__bridge void *)self.stringBuilder);
    sd_markdown_render(outputBuffer, inputBuffer->data, inputBuffer->size, markdown);
    sd_markdown_free(markdown);
    
//    NSData *outputData = [NSData dataWithBytes:outputBuffer->data length:outputBuffer->size];
//    NSString *outputString = [[NSString alloc] initWithData:outputData encoding:NSUTF8StringEncoding];

    return self.stringBuilder.attributedString;
}

@end


