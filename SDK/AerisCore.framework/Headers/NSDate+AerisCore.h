//
//  NSDate+AerisCore.h
//  AerisCore
//
//  Created by Nicholas Shipes on 11/20/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
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
extern NSString * const AWFDateFormatMonthWithZeroPadding;
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
extern NSString * const AWFDateFormatMinutesWithZeroPadding;
extern NSString * const AWFDateFormatSeconds;
extern NSString * const AWFDateFormatPeriod;
extern NSString * const AWFDateFormatTimeZoneName;
extern NSString * const AWFDateFormatTimeZoneOffset;
extern NSString * const AWFDateFormatTimeZoneLocation;

@interface NSDate (AerisCore)

@property (readonly, nonatomic) NSInteger awf_era;
@property (readonly, nonatomic) NSInteger awf_year;
@property (readonly, nonatomic) NSInteger awf_month;
@property (readonly, nonatomic) NSInteger awf_day;
@property (readonly, nonatomic) NSInteger awf_hour;
@property (readonly, nonatomic) NSInteger awf_minute;
@property (readonly, nonatomic) NSInteger awf_second;
@property (readonly, nonatomic) NSInteger awf_weekday;
@property (readonly, nonatomic) NSInteger awf_weekdayOrdinal;
@property (readonly, nonatomic) NSInteger awf_quarter;
@property (readonly, nonatomic) NSInteger awf_weekOfMonth;
@property (readonly, nonatomic) NSInteger awf_weekOfYear;
@property (readonly, nonatomic) NSInteger awf_yearForWeekOfYear;
@property (readonly, nonatomic) NSInteger awf_daysInMonth;
@property (readonly, nonatomic) NSInteger awf_dayOfYear;
@property (readonly, nonatomic) NSInteger awf_daysInYear;
@property (readonly, nonatomic) NSTimeZone *awf_timeZone;

//-----------------------------------------------------------------------------
// @name Time Ago
//-----------------------------------------------------------------------------

+ (NSString *)awf_timeAgoSinceDate:(NSDate *)date;
- (NSString *)awf_timeAgoSinceNow;
- (NSString *)awf_timeAgoSinceDate:(NSDate *)date;
- (NSString *)awf_timeAgoSinceDate:(NSDate *)date usingNumericDates:(BOOL)useNumericDates;
- (NSString *)awf_timeAgoSinceDate:(NSDate *)date usingNumericDates:(BOOL)useNumericDates numericTimes:(BOOL)useNumericTimes;

//-----------------------------------------------------------------------------
// @name Date Components
//-----------------------------------------------------------------------------

- (BOOL)awf_isInLeapYear;
- (BOOL)awf_isToday;
- (BOOL)awf_isTomorrow;
- (BOOL)awf_isYesterday;
- (BOOL)awf_isWeekend;
- (BOOL)awf_isSameDay:(NSDate *)date;
+ (BOOL)awf_isSameDay:(NSDate *)date asDate:(NSDate *)compareDate;
- (BOOL)awf_isDaylightSavingsTime;

//-----------------------------------------------------------------------------
// @name Day Periods
//-----------------------------------------------------------------------------

- (BOOL)awf_isEarlyMorning;
- (BOOL)awf_isMorning;
- (BOOL)awf_isMidday;
- (BOOL)awf_isAfternoon;
- (BOOL)awf_isEvening;
- (BOOL)awf_isNight;
- (BOOL)awf_isDay;
- (BOOL)awf_isTonight;
- (BOOL)awf_isPM;

//-----------------------------------------------------------------------------
// @name Creating Dates
//-----------------------------------------------------------------------------

+ (NSDate *)awf_dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;
+ (NSDate *)awf_dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day timeZone:(NSTimeZone *)timeZone;
+ (NSDate *)awf_dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day hour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second;
+ (NSDate *)awf_dateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day hour:(NSInteger)hour minute:(NSInteger)minute second:(NSInteger)second timeZone:(NSTimeZone *)timeZone;
+ (NSDate *)awf_dateWithString:(NSString *)dateString;
+ (NSDate *)awf_dateWithString:(NSString *)dateString formatString:(NSString *)formatString;
+ (NSDate *)awf_dateWithString:(NSString *)dateString formatString:(NSString *)formatString timeZone:(NSTimeZone *)timeZone;
+ (NSDate *)awf_relativeDateWithString:(NSString *)dateString;
- (NSDate *)awf_dateWithTimeZone:(NSTimeZone *)timeZone;

//-----------------------------------------------------------------------------
// @name Modifying Dates
//-----------------------------------------------------------------------------

- (NSDate *)awf_dateByAddingYears:(NSInteger)years;
- (NSDate *)awf_dateByAddingMonths:(NSInteger)months;
- (NSDate *)awf_dateByAddingWeeks:(NSInteger)weeks;
- (NSDate *)awf_dateByAddingDays:(NSInteger)days;
- (NSDate *)awf_dateByAddingHours:(NSInteger)hours;
- (NSDate *)awf_dateByAddingMinutes:(NSInteger)minutes;
- (NSDate *)awf_dateByAddingSeconds:(NSInteger)seconds;
- (NSDate *)awf_dateBySubtractingYears:(NSInteger)years;
- (NSDate *)awf_dateBySubtractingMonths:(NSInteger)months;
- (NSDate *)awf_dateBySubtractingWeeks:(NSInteger)weeks;
- (NSDate *)awf_dateBySubtractingDays:(NSInteger)days;
- (NSDate *)awf_dateBySubtractingHours:(NSInteger)hours;
- (NSDate *)awf_dateBySubtractingMinutes:(NSInteger)minutes;
- (NSDate *)awf_dateBySubtractingSeconds:(NSInteger)seconds;
- (NSDate *)awf_dateByIgnoringTime;
- (NSDate *)awf_dateByIgnoringSeconds;

//-----------------------------------------------------------------------------
// @name Date Comparison
//-----------------------------------------------------------------------------

- (NSInteger)awf_yearsFrom:(NSDate *)date;
- (NSInteger)awf_monthsFrom:(NSDate *)date;
- (NSInteger)awf_weeksFrom:(NSDate *)date;
- (NSInteger)awf_daysFrom:(NSDate *)date;
- (double)awf_hoursFrom:(NSDate *)date;
- (double)awf_minutesFrom:(NSDate *)date;
- (double)awf_secondsFrom:(NSDate *)date;
- (BOOL)awf_isEarlierThan:(NSDate *)date;
- (BOOL)awf_isLaterThan:(NSDate *)date;
- (BOOL)awf_isEarlierThanOrEqualTo:(NSDate *)date;
- (BOOL)awf_isLaterThanOrEqualTo:(NSDate *)date;
- (BOOL)awf_isEqualToDateIgnoringTime:(NSDate *)date;
- (BOOL)awf_isEarlierThanDateIgnoringTime:(NSDate *)date;
- (BOOL)awf_isLaterThanDateIgnoringTime:(NSDate *)date;
- (BOOL)awf_isFuture;


//-----------------------------------------------------------------------------
// @name Formatting
//-----------------------------------------------------------------------------

- (NSString *)awf_formattedDateWithStyle:(NSDateFormatterStyle)style;
- (NSString *)awf_formattedDateWithStyle:(NSDateFormatterStyle)style timeZone:(NSTimeZone *)timeZone;
- (NSString *)awf_formattedDateWithStyle:(NSDateFormatterStyle)style locale:(NSLocale *)locale;
- (NSString *)awf_formattedDateWithStyle:(NSDateFormatterStyle)style timeZone:(NSTimeZone *)timeZone locale:(NSLocale *)locale;
- (NSString *)awf_formattedDateWithFormat:(NSString *)format;
- (NSString *)awf_formattedDateWithFormat:(NSString *)format timeZone:(NSTimeZone *)timeZone;
- (NSString *)awf_formattedDateWithFormat:(NSString *)format locale:(NSLocale *)locale;
- (NSString *)awf_formattedDateWithFormat:(NSString *)format timeZone:(NSTimeZone *)timeZone locale:(NSLocale *)locale;
- (NSString *)awf_dateStringRelativeToNowUsingInterval:(NSTimeInterval)interval;
- (NSString *)awf_dateStringRelativeToDate:(NSDate *)date usingInterval:(NSTimeInterval)interval;
- (NSString *)awf_dayNameRelativeToNow:(BOOL)includingNight;
- (NSString *)awf_dayNameRelativeToNow:(BOOL)includingNight timeZone:(NSTimeZone *)timeZone;

@end
