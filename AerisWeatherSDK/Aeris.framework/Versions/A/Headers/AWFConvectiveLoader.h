//
//  AWFConvectiveLoader.h
//  Aeris
//
//  Created by Nicholas Shipes on 11/5/15.
//  Copyright © 2015 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObjectLoader.h>

extern NSString * const AWFConvectiveOutlookFilterCategorical;
extern NSString * const AWFConvectiveOutlookFilterProbability;
extern NSString * const AWFConvectiveOutlookFilterAllHazards;

extern NSString * const AWFConvectiveOutlookFilterAll;
extern NSString * const AWFConvectiveOutlookFilterTornado;
extern NSString * const AWFConvectiveOutlookFilterSignificantTornado;
extern NSString * const AWFConvectiveOutlookFilterAllTornado;
extern NSString * const AWFConvectiveOutlookFilterHail;
extern NSString * const AWFConvectiveOutlookFilterSignificantHail;
extern NSString * const AWFConvectiveOutlookFilterAllHail;
extern NSString * const AWFConvectiveOutlookFilterWind;
extern NSString * const AWFConvectiveOutlookFilterSignificantWind;
extern NSString * const AWFConvectiveOutlookFilterAllWind;

extern NSString * const AWFConvectiveOutlookFilterGeneral;
extern NSString * const AWFConvectiveOutlookFilterMarginal;
extern NSString * const AWFConvectiveOutlookFilterSlight;
extern NSString * const AWFConvectiveOutlookFilterEnhanced;
extern NSString * const AWFConvectiveOutlookFilterModerate;
extern NSString * const AWFConvectiveOutlookFilterHigh;

extern NSString * const AWFConvectiveOutlookFilterDay1;
extern NSString * const AWFConvectiveOutlookFilterDay2;
extern NSString * const AWFConvectiveOutlookFilterDay3;
extern NSString * const AWFConvectiveOutlookFilterDay4;
extern NSString * const AWFConvectiveOutlookFilterDay5;
extern NSString * const AWFConvectiveOutlookFilterDay6;
extern NSString * const AWFConvectiveOutlookFilterDay7;
extern NSString * const AWFConvectiveOutlookFilterDay8;

extern NSString * const AWFConvectiveOutlookFieldId;
extern NSString * const AWFConvectiveOutlookFieldCategory;
extern NSString * const AWFConvectiveOutlookFieldRiskType;
extern NSString * const AWFConvectiveOutlookFieldRiskName;
extern NSString * const AWFConvectiveOutlookFieldRiskCode;
extern NSString * const AWFConvectiveOutlookFieldDay;
extern NSString * const AWFConvectiveOutlookFieldStartDate;
extern NSString * const AWFConvectiveOutlookFieldEndDate;
extern NSString * const AWFConvectiveOutlookFieldIssuedDate;

/**
 *  `AWFConvectiveOutlooksLoader` provides conveninece methods for interacting with the 
 *  [`convective` endpoint](http://www.aerisweather.com/support/docs/api/reference/endpoints/convective/outlook) of the Aeris API. All requests will return 
 *  instances of `AWFConvectiveOutlook` that will be populated with the data returned from the API unless otherwise indicated.
 */
@interface AWFConvectiveOutlooksLoader : AWFGeographicObjectLoader

@end
