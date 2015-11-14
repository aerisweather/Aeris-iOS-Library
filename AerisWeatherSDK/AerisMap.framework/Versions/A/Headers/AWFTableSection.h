//
//  AWFTableSection.h
//  AerisMap
//
//  Created by Nicholas Shipes on 6/25/15.
//  Copyright (c) 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AWFTableSectionRow;

/**
 *  An `AWFTableSection` object is a convenience class to manage an array of sections and rows to display within a `UITableView`.
 */
@interface AWFTableSection : NSObject

/**
 *  The title to display for the section.
 */
@property (copy, nonatomic) NSString *title;

/**
 *  The text to display for the section's footer.
 */
@property (copy, nonatomic) NSString *footerTitle;

/**
 *  An array of `AWFTableSectionRow` instances to display within the section.
 */
@property (readonly, strong, nonatomic) NSArray *rows;

/**
 *  Creates and returns a `AWFTableSection` instance initialized with the specified title.
 *
 *  @param title The title of the section
 *
 *  @return An initialized section with the title
 */
+ (instancetype)sectionWithTitle:(NSString *)title;

/**
 *  Creates and returns a `AWFTableSection` instance initialized with the specified title and array of rows.
 *
 *  @param title The title of the section
 *  @param rows  The rows to display with the section
 *
 *  @return An initialized section with the title and rows
 */
+ (instancetype)sectionWithTitle:(NSString *)title rows:(NSArray *)rows;

/**
 *  Adds a new row to the section. The row will be added to the end of the `rows` array.
 *
 *  @param row The row to add
 */
- (void)addRow:(AWFTableSectionRow *)row;

/**
 *  Adds an array of rows to the section. The rows will be added to the end of the `rows` array.
 *
 *  @param rows An array of rows to add
 */
- (void)addRows:(NSArray *)rows;

/**
 *  Removes a row from the section.
 *
 *  @param row The row to remove
 */
- (void)removeRow:(AWFTableSectionRow *)row;

/**
 *  Removes an array of rows from the array.
 *
 *  @param rows An array of rows to remove
 */
- (void)removeRows:(NSArray *)rows;

/**
 *  Removes all rows from the section.
 */
- (void)removeAllRows;

@end
