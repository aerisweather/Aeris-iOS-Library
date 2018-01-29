//
//  AWFPropertyDescriptor.h
//  Aeris-API-Library
//
//  Created by Nicholas Shipes on 3/23/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AWFProperty(property) ({[[AWFPropertyDescriptor alloc] initWithPropertyName:@#property];})
#define AWFPropertyEncode(property) ({[[AWFPropertyDescriptor alloc] initWithPropertyName:@#property mode:AWFPropertyMapperCodificationModeEncode];})
#define AWFPropertyDecode(property) ({[[AWFPropertyDescriptor alloc] initWithPropertyName:@#property mode:AWFPropertyMapperCodificationModeDecode];})
#define AWFClass(property, klass) ({[[AWFPropertyDescriptor alloc] initWithPropertyName:@#property class:klass];})
#define AWFClassProperty(classProperty, property, klass) ({[[AWFPropertyDescriptor alloc] initWithPropertyName:@#property classPropertyName:@#classProperty class:klass];})
#define AWFClassEncode(property, klass) ({[[AWFPropertyDescriptor alloc] initWithPropertyName:@#property class:klass mode:AWFPropertyMapperCodificationModeEncode];})
#define AWFClassDecode(property, klass) ({[[AWFPropertyDescriptor alloc] initWithPropertyName:@#property class:klass mode:AWFPropertyMapperCodificationModeDecode];})
#define AWFBlock(property, encoder, decoder) ({[[AWFPropertyDescriptor alloc] initWithPropertyName:@#property encodingBlock:encoder decodingBlock:decoder];})
//#define AWFTimestampBlock(property) ({[[AWFPropertyDescriptor alloc] initWithPropertyName:@#property encodingBlock:^(id input, NSString *propertyName) { return @([(NSDate *)input timeIntervalSince1970]); } decodingBlock:^(id input, NSString *propertyName) { return [NSDate dateWithTimeIntervalSince1970:[input intValue]]; }];})
#define AWFGenerationConsumerBlock(encoder, decoder) ({[[AWFPropertyDescriptor alloc] initWithEncodingGenerationBlock:encoder decodingGenerationBlock:decoder];})

#define AWFTimestampBlock(property) ({ AWFTimestampDescriptor(@#property); })
id AWFTimestampDescriptor(NSString *property);

typedef NS_ENUM(NSUInteger, AWFPropertyMapperCodificationMode) {
	AWFPropertyMapperCodificationModeEncode			= 1,
	AWFPropertyMapperCodificationModeDecode			= 2,
	AWFPropertyMapperCodificationModeEncodeDecode	= 3
};

typedef NS_ENUM(NSUInteger, AWFPropertyDescriptorType) {
	AWFPropertyDescriptorTypeDirect,
	AWFPropertyDescriptorTypeClass,
	AWFPropertyDescriptorTypeClassProperty,
	AWFPropertyDescriptorTypeSymmetricalBlock,
	AWFPropertyDescriptorTypeAsymmetricalBlock
};

typedef id(^AWFValueTransformerBlock)(id input, NSString *propertyName);
typedef id(^AWFValueGenerationBlock)(id object);
typedef void(^AWFValueConsumerBlock)(id input, id object);

@interface AWFPropertyDescriptor : NSObject

@property (readonly, nonatomic) NSString *propertyName;
@property (readonly, nonatomic) Class propertyClass;
@property (readonly, nonatomic) NSString *classPropertyName;
@property (readonly, nonatomic) NSMutableArray *validationBlocks;

@property (readonly, nonatomic) AWFValueTransformerBlock encodingBlock;
@property (readonly, nonatomic) AWFValueTransformerBlock decodingBlock;
@property (readonly, nonatomic) AWFValueGenerationBlock encodingGenerationBlock;
@property (readonly, nonatomic) AWFValueConsumerBlock decodingConsumerBlock;
@property (readonly, nonatomic) enum AWFPropertyMapperCodificationMode mode;
@property (readonly, nonatomic) enum AWFPropertyDescriptorType type;

- (instancetype)initWithPropertyName:(NSString *)propertyName;
- (instancetype)initWithPropertyName:(NSString *)propertyName mode:(enum AWFPropertyMapperCodificationMode)mode;
- (instancetype)initWithPropertyName:(NSString *)propertyName class:(Class)klass;
- (instancetype)initWithPropertyName:(NSString *)propertyName class:(Class)klass mode:(enum AWFPropertyMapperCodificationMode)mode;
- (instancetype)initWithPropertyName:(NSString *)propertyName classPropertyName:(NSString *)classPropertyName class:(Class)klass;
- (instancetype)initWithPropertyName:(NSString *)propertyName encodingBlock:(AWFValueTransformerBlock)encoder decodingBlock:(AWFValueTransformerBlock)decoder;
- (instancetype)initWithEncodingGenerationBlock:(AWFValueGenerationBlock)encoder decodingConsumerBlock:(AWFValueConsumerBlock)decoder;

- (void)addValidatorWithName:(NSString *)name validation:(BOOL (^)(id value))validator;
- (NSArray *)validateValue:(id)value;

@end
