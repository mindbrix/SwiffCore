/*
    SwiftParser.h
    Copyright (c) 2011, musictheory.net, LLC.  All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of musictheory.net, LLC nor the names of its contributors
          may be used to endorse or promote products derived from this software
          without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL MUSICTHEORY.NET, LLC BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import <SwiftImport.h>
#import <SwiftBase.h>


typedef struct _SwiftParser SwiftParser;

extern SwiftParser *SwiftParserCreate(const UInt8 *buffer, UInt32 length);
extern void SwiftParserFree(SwiftParser *reader);

extern BOOL SwiftParserReadHeader(SwiftParser *parser, SwiftHeader *outHeader);

extern void SwiftParserAdvance(SwiftParser *parser, UInt32 length);
extern BOOL SwiftParserIsValid(SwiftParser *parser);

// Allow the parser to store key-value pairs at parse time
extern void SwiftParserSetAssociatedValue(SwiftParser *parser, NSString *key, id value);
extern id   SwiftParserGetAssociatedValue(SwiftParser *parser, NSString *key);

extern const UInt8 *SwiftParserGetCurrentBytePointer(SwiftParser *parser);

// The encoding to use for STRINGs, defaults to NSUTF8StringEncoding
extern void SwiftParserSetStringEncoding(SwiftParser *parser, NSStringEncoding encoding);
extern NSStringEncoding SwiftParserGetStringEncoding(SwiftParser *parser);


// Tags
//
extern void SwiftParserAdvanceToNextTag(SwiftParser *parser);
extern UInt32 SwiftParserGetBytesRemainingInCurrentTag(SwiftParser *parser);

extern SwiftTag  SwiftParserGetCurrentTag(SwiftParser *parser);
extern NSInteger SwiftParserGetCurrentTagVersion(SwiftParser *parser);


// Bitfields
//
extern void SwiftParserByteAlign(SwiftParser *parser);

extern void SwiftParserReadFBits(SwiftParser *parser, UInt8 numberOfBits, CGFloat *outValue);
extern void SwiftParserReadSBits(SwiftParser *parser, UInt8 numberOfBits, SInt32 *outValue);
extern void SwiftParserReadUBits(SwiftParser *parser, UInt8 numberOfBits, UInt32 *outValue);


// Primitives
//
extern void SwiftParserReadUInt8(SwiftParser *parser, UInt8 *outValue);
extern void SwiftParserReadUInt16(SwiftParser *parser, UInt16 *outValue);
extern void SwiftParserReadUInt32(SwiftParser *parser, UInt32 *outValue);

extern void SwiftParserReadSInt8(SwiftParser *parser, SInt8 *outValue);
extern void SwiftParserReadSInt16(SwiftParser *parser, SInt16 *outValue);
extern void SwiftParserReadSInt32(SwiftParser *parser, SInt32 *outValue);

extern void SwiftParserReadFixed8(SwiftParser *parser, CGFloat *outValue);

extern void SwiftParserReadEncodedU32(SwiftParser *parser, UInt32 *outValue);


// Structs
//
extern void SwiftParserReadRect(SwiftParser *parser, CGRect *outValue);
extern void SwiftParserReadMatrix(SwiftParser *parser, CGAffineTransform *outMatrix);

extern void SwiftParserReadColorRGB(SwiftParser *parser, SwiftColor *outValue);
extern void SwiftParserReadColorRGBA(SwiftParser *parser, SwiftColor *outValue);
extern void SwiftParserReadColorARGB(SwiftParser *parser, SwiftColor *outValue);

extern void SwiftParserReadColorTransform(SwiftParser *parser, SwiftColorTransform *colorTransform);
extern void SwiftParserReadColorTransformWithAlpha(SwiftParser *parser, SwiftColorTransform *colorTransform);


// Objects
//
extern void SwiftParserReadData(SwiftParser *parser, UInt32 length, NSData **outValue);

extern void SwiftParserReadString(SwiftParser *parser, NSString **outValue);
extern void SwiftParserReadLengthPrefixedString(SwiftParser *parser, NSString **outValue);
