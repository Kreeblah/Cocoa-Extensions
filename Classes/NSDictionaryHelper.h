/* *********************************************************************

        Copyright (c) 2010 - 2015 Codeux Software, LLC
     Please see ACKNOWLEDGEMENT for additional information.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
 * Neither the name of "Codeux Software, LLC", nor the names of its 
   contributors may be used to endorse or promote products derived 
   from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 SUCH DAMAGE.

 *********************************************************************** */

NS_ASSUME_NONNULL_BEGIN

#define NSDictionaryNilValue(s)							(((s) == nil) ? [NSNull null] : (s))
#define NSDictionaryNilValueSubstitue(s, r)				(((s) == nil) ? (r) : (s))

@interface NSDictionary (CSDictionaryHelper)
- (nullable NSString *)stringForKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key;
- (nullable NSArray *)arrayForKey:(NSString *)key;
- (nullable NSDictionary *)dictionaryForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
- (NSUInteger)unsignedIntegerForKey:(NSString *)key;
- (long long)longLongForKey:(NSString *)key;
- (double)doubleForKey:(NSString *)key;
- (float)floatForKey:(NSString *)key;
- (nullable void *)pointerForKey:(NSString *)key NS_RETURNS_INNER_POINTER;

- (nullable id)objectForKey:(id)key orUseDefault:(nullable id)defaultValue;
- (nullable NSString *)stringForKey:(id)key orUseDefault:(nullable NSString *)defaultValue;
- (BOOL)boolForKey:(NSString *)key orUseDefault:(BOOL)defaultValue;
- (nullable NSArray *)arrayForKey:(NSString *)key orUseDefault:(nullable NSArray *)defaultValue;
- (nullable NSDictionary *)dictionaryForKey:(NSString *)key orUseDefault:(nullable NSDictionary *)defaultValue;
- (NSInteger)integerForKey:(NSString *)key orUseDefault:(NSInteger)defaultValue;
- (NSUInteger)unsignedIntegerForKey:(NSString *)key orUseDefault:(NSInteger)defaultValue;
- (long long)longLongForKey:(NSString *)key orUseDefault:(long long)defaultValue;
- (double)doubleForKey:(NSString *)key orUseDefault:(double)defaultValue;
- (float)floatForKey:(NSString *)key orUseDefault:(float)defaultValue;

/* Objects are copied to the pointer using -copy */
- (void)assignObjectTo:(__strong _Nonnull id * _Nonnull)pointer forKey:(NSString *)key;
- (void)assignStringTo:(__strong NSString * _Nonnull * _Nonnull)pointer forKey:(NSString *)key;
- (void)assignBoolTo:(BOOL *)pointer forKey:(NSString *)key;
- (void)assignArrayTo:(__strong NSArray * _Nonnull * _Nonnull)pointer forKey:(NSString *)key;
- (void)assignDictionaryTo:(__strong NSDictionary * _Nonnull * _Nonnull)pointer forKey:(NSString *)key;
- (void)assignIntegerTo:(NSInteger *)pointer forKey:(NSString *)key;
- (void)assignUnsignedIntegerTo:(NSUInteger *)pointer forKey:(NSString *)key;
- (void)assignLongLongTo:(long long *)pointer forKey:(NSString *)key;
- (void)assignDoubleTo:(double *)pointer forKey:(NSString *)key;
- (void)assignFloatTo:(float *)pointer forKey:(NSString *)key;

- (nullable id)firstKeyForObject:(id)anObject;

- (BOOL)containsKey:(NSString *)baseKey;
- (BOOL)containsKeyIgnoringCase:(NSString *)baseKey;

- (nullable id)keyIgnoringCase:(id)baseKey;

@property (readonly, copy) NSArray *sortedDictionaryKeys;
@property (readonly, copy) NSArray *sortedDictionaryReversedKeys;

/* Returns a new dictionary without values that are already defined by "defaults" 
 or are empty (zero length, or zero count). This method is not recursive which 
 means it only performs one pass on all top level objects. */
/* "defaults" is allowed to be nil in which case only empty objects are removed. */
- (NSDictionary *)dictionaryByRemovingDefaults:(nullable NSDictionary *)defaults;
- (NSDictionary *)dictionaryByRemovingDefaults:(nullable NSDictionary *)defaults allowEmptyValues:(BOOL)allowEmptyValues;
@end

@interface NSMutableDictionary (CSMutableDictionaryHelper)
/* maybeSetObject provides nil checks for inserted objects. */
- (void)maybeSetObject:(nullable id)value forKey:(NSString *)key;

- (void)setObjectWithoutOverride:(id)value forKey:(NSString *)key;

- (void)setBool:(BOOL)value forKey:(NSString *)key;
- (void)setInteger:(NSInteger)value forKey:(NSString *)key;
- (void)setUnsignedInteger:(NSUInteger)value forKey:(NSString *)key;
- (void)setLongLong:(long long)value forKey:(NSString *)key;
- (void)setDouble:(double)value forKey:(NSString *)key;
- (void)setFloat:(float)value forKey:(NSString *)key;
- (void)setPointer:(void *)value forKey:(NSString *)key;
@end

NS_ASSUME_NONNULL_END
