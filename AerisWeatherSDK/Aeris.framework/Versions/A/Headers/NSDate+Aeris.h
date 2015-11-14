//
//  NSDate+Aeris.h
//  Aeris
//
//  Created by Nicholas Shipes on 6/23/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, AWFDay) {
	AWFDaySunday	= 1,
	AWFDayMonday	= 2,
	AWFDayTuesday	= 3,
	AWFDayWednesday = 4,
	AWFDayThursday	= 5,
	AWFDayFriday	= 6,
	AWFDaySaturday	= 7
};

typedef NS_OPTIONS(NSUInteger, AWFMonth) {
	AWFMonthJanuary		= 1,
	AWFMonthFebruary	= 2,
	AWFMonthMarch		= 3,
	AWFMonthApril		= 4,
	AWFMonthMay			= 5,
	AWFMonthJune		= 6,
	AWFMonthJuly		= 7,
	AWFMonthAugust		= 8,
	AWFMonthSeptember	= 9,
	AWFMonthOctober		= 10,
	AWFMonthNovember	= 11,
	AWFMonthDecember	= 12
};

extern NSTimeInterval const AWFSecondInterval;
extern NSTimeInterval const AWFMinuteInterval;
extern NSTimeInterval const AWFHourInterval;
extern NSTimeInterval const AWFDayInterval;
extern NSTimeInterval const AWFWeekInterval;
extern NSTimeInterval const AWFMonthInterval;
extern NSTimeInterval const AWFYearInterval;

extern NSString * const AWFDateFormatYear;
extern NSString * const AWFDateFormatMonth;
extern NSString * const AWFDateFormatMonthName;
extern NSString * const AWFDateFormatMonthNameFull;
extern NSString * const AWFDateFormatDate;
extern NSString * const AWFDateFormatDateWithZeroPadding;
extern NSString * const AWFDateFormatDay;
extern NSString * const AWFDateFormatDayName;
extern NSString * const AWFDateFormatDayNameFull;
extern NSString * const AWFDateFormatDayOfYear;
extern NSString * const AWFDateFormatHour;
extern NSString * const AWFDateFormatHourWithZeroPadding;
extern NSString * const AWFDateFormatHour24;
extern NSString * const AWFDateFormatHour24WithZeroPadding;
extern NSString * const AWFDateFormatMinutes;
extern NSString * const AWFDateFormatSeconds;
extern NSString * const AWFDateFormatPeriod;
extern NSString * const AWFDateFormatTimeZoneName;
extern NSString * const AWFDateFormatTimeZoneOffset;
extern NSString * const AWFDateFormatTimeZoneLocation;

@interface NSDate (Aeris)

+ (NSDateFormatter *)awf_formatter;
+ (NSCalendar *)awf_calendar;

//----------------------
// @name String Conversions
//----------------------

+ (NSString *)awf_timeAgoSinceInterval:(NSTimeInterval)interval includingSeconds:(BOOL)includeSeconds;
+ (NSDate *)awf_dateFromISO8601String:(NSString *)iso8601;

- (NSString *)awf_stringValue;
- (NSString *)awf_shortStringValue;
- (NSString *)awf_stringWithFormat:(NSString *)format;
- (NSString *)awf_stringWithFormat:(NSString *)format usingTimeZone:(NSTimeZone *)timeZone;

- (NSString *)awf_dayRelativeToNow;
- (NSString *)awf_dayRelativeToNowUsingTimeZone:(NSTimeZone *)timeZone;
- (NSString *)awf_timeAgo;
- (NSString *)awf_ISO8601String;
- (NSString *)awf_ISO8601StringWithTimeZone:(NSTimeZone *)timeZone;

- (NSString *)awf_dateStringRelativeToNowUsingInterval:(NSTimeInterval)interval;
- (NSString *)awf_dateStringRelativeToDate:(NSDate *)date usingInterval:(NSTimeInterval)interval;

+ (NSDate *)awf_dateFromString:(NSString *)dateString;
+ (NSDate *)awf_dateFromRelativeString:(NSString *)relativeString;

//-----------------------------------------------------------------------------
// @name Date Conversions
//-----------------------------------------------------------------------------

- (NSDate *)awf_nextDay;
- (NSDate *)awf_previousDay;

- (NSDate *)awf_nextWeek;
- (NSDate *)awf_previousWeek;

- (NSDate *)awf_dateByAddingDays:(NSInteger)days ignoringTime:(BOOL)ignoringTime;
- (NSDate *)awf_dateByAddingTimeInterval:(NSTimeInterval)interval;

- (NSDate *)awf_nextDateOfDateName:(AWFDay)day;
- (NSDate *)awf_previousDateOfDateName:(AWFDay)day;

- (NSDate *)awf_dateByIgnoringTime;
- (NSDate *)awf_dateByIgnoringSeconds;

//----------------------
// @name Date Comparisons
//----------------------

- (BOOL)awf_isToday;
- (BOOL)awf_isTomorrow;
- (BOOL)awf_isYesterday;
- (BOOL)awf_isEarlyMorning;
- (BOOL)awf_isMorning;
- (BOOL)awf_isMidday;
- (BOOL)awf_isAfternoon;
- (BOOL)awf_isEvening;
- (BOOL)awf_isNight;
- (BOOL)awf_isDay;
- (BOOL)awf_isTonight;
- (BOOL)awf_isPM;
- (BOOL)awf_isDaylightSavingsTime;
- (BOOL)awf_isEqualToDateIgnoringTime:(NSDate *)date;
- (BOOL)awf_isSameWeekAsDate:(NSDate *)date;
- (BOOL)awf_isEarlierThanDate:(NSDate *)date;
- (BOOL)awf_isEarlierThanDateIgnoringTime:(NSDate *)date;
- (BOOL)awf_isLaterThanDate:(NSDate *)date;
- (BOOL)awf_isLaterThanDateIgnoringTime:(NSDate *)date;

//----------------------
// @name Timezones
//----------------------

+ (NSTimeZone *)awf_timeZoneFromISO8601String:(NSString *)iso8601;
+ (void)awf_setDefaultTimezone:(NSTimeZone *)timeZone;
+ (NSTimeZone *)awf_defaultTimezone;
- (NSInteger)awf_GMTOffsetSeconds;

//----------------------
// @name Date Components
//----------------------

+ (NSDate *)awf_dateForYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;
+ (NSDate *)awf_dateForYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day
				   timeZone:(NSTimeZone *)timeZone;
+ (NSDate *)awf_dateForYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day
					   hour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second;
+ (NSDate *)awf_dateForYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day
					   hour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second
				   timeZone:(NSTimeZone *)timeZone;

@property (readonly) NSInteger hour;
@property (readonly) NSInteger minute;
@property (readonly) NSInteger seconds;
@property (readonly) NSInteger day;
@property (readonly) NSInteger month;
@property (copy, readonly) NSString *monthName;
@property (readonly) NSInteger week;
@property (readonly) NSInteger weekday;
@property (copy, readonly) NSString *weekdayName;
@property (readonly) NSInteger nthWeekday;	// e.g., 2nd Tuesday of the month == 2
@property (readonly) NSInteger year;

@end
