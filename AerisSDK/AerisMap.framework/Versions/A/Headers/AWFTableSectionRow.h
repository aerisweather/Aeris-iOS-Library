//
//  AWFTableSectionRow.h
//  AerisMap
//
//  Created by Nicholas Shipes on 6/25/15.
//  Copyright (c) 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  An `AWFTableSectionRow` object manages a single row option that is displayed within a `UITableView`.
 */
@interface AWFTableSectionRow : NSObject

/**
 *  The title to display for the row.
 */
@property (copy, nonatomic) NSString *title;

/**
 *  The value to associate with the row, if any. This should be defined if this cell requires a selected/deselected state.
 */
@property (strong, nonatomic) id value;

/**
 *  The cell identifier used when dequeuing a `UITableViewCell` instance from the parent table view.
 */
@property (copy, nonatomic) NSString *cellIdentifier;

/**
 *  Creates and returns an `AWFTableSectionRow` instance initialized with the specified title and value.
 *
 *  @param title The title to display for the row
 *  @param value The value for the row (optional)
 *
 *  @return An initialized section row for the title and value
 */
+ (instancetype)rowWithTitle:(NSString *)title value:(id)value;

/**
 *  Creates and returns an `AWFTableSectionRow` instance initialized with the specified title, value and cellIdentifier.
 *
 *  @param title          The title to display for the row
 *  @param value          The value for the row (optional)
 *  @param cellIdentifier The cell identifier for the `UITableViewCell` class to use when configuring the table view cell for this row
 *
 *  @return An initialized section row for the title, value and cell identifier
 */
+ (instancetype)rowWithTitle:(NSString *)title value:(id)value cellIdentifier:(NSString *)cellIdentifier;

@end
