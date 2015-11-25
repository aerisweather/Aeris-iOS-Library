Aeris iOS Weather SDK 2.0
=============

The [Aeris iOS Weather Framework](http://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk/) allows a developer to quickly and easily add weather content and functionality to their iOS applications quickly and easily without having to code anything themselves. It utilizes the [Aeris API](http://www.aerisweather.com/support/docs/api/) backend for data loading and is built on top of an object mapping system that efficiently loads requested weather content into third-party iOS applications, greatly reducing the amount of code and development needed on the developer end.

## Components

The AerisWeather SDK is broken up into multiple frameworks, allowing you to only include the components you need. However, some of the components have dependencies on one or more of the others as it simple builds upon them. 

* **Aeris.framework** - Base library used to interact with and parse Aeris Weather API data. 
* **AerisUI.framework** - UI utilities and components, (graphs, views) and built-in weather views
	* requires Aeris.framework
* **AerisMap.framework** - Fully functional interactive weather map using the Aeris Overlays service.
	* requires Aeris.framework, AerisUI.framework
* **AerisMapboxMap.framework** - Extension of the AerisMap library to support using Mapbox base maps
	* requires Aeris.framework, AerisUI.framework, AerisMap.framework
	* requires [MBXMapKit](https://github.com/mapbox/mbxmapkit)
* **AerisGoogleMap.framework** - Extension of the AerisMap library to support using the Google Maps SDK.
	* requires Aeris.framework, AerisUI.framework, AerisMap.framework
	* requires [GoogleMaps](https://developers.google.com/maps/documentation/ios-sdk/)
	
## Setup

### Using [CocoaPods](http://cocoapods.org)

1. Add the pod `AerisWeather` to your Podfile. This will add the base Aeris.framework as a dependency to your project.
	
	```ruby
	pod 'AerisWeather'
	```
2. If you wish to install multiple AerisWeather components, add them as dependencies to your Podfile as well:

	```ruby
	pod 'AerisWeather/AerisUI'
	pod 'AerisWeather/AerisMap'
	pod 'AerisWeather/AerisMapboxMap'
	pod 'AerisWeather/AerisGoogleMap'
	```

3. Run `pod install` from Terminal, then open your project's `.xcworkspace` file to launch Xcode.
4. Import the necessary umbrella headers for the AerisWeather components you wish to use (e.g. *Aeris*, *AerisUI*, *AerisMap*, etc):
   	* With `use_frameworks!` in your Podfile
    	* Swift: `import Aeris`
    	* Objective-C: `#import <Aeris/Aeris.h>`
	* Without `use_frameworks!` in your Podfile
    	* Swift: Add `#import "<Aeris/Aeris.h>"` to your bridging header.
    	* Objective-C: `#import "<Aeris/Aeris.h>"`

### Manually from Github

1. Checkout or download the [Aeris-iOS-Libary repo](https://github.com/aerisweather/Aeris-iOS-Library).
2. Add the necessary Aeris framework components to your Xcode target from the downloaded files. These components are located under the **AerisWeatherSDK** directory.
3. Import the necessary framework headers for each Aeris component you are using (e.g. *Aeris*, *AerisUI*, *AerisMap*, etc):

	```objc
 	#import <Aeris/Aeris.h>
 	#import <AerisUI/AerisUI.h>
 	#import <AerisMap/AerisMap.h>
 	...
	```

## Demo

Check out the included demo project, under the **AerisSDKDemo** directory, which contains a variety of example views using different components of the SDK, including the built-in weather views and weather maps with different mapping libraries. Since the project's dependencies (specifically AFNetworking) in the demo project are installed and managed using [CocoaPods](http://cocoapods.org), you will need to open the **AerisSDKDemo/AerisSDKDemo.xcworkspace**.

The various components of the Aeris iOS Weather SDK are located under the **AerisSDK** directory. These are the libraries you will be using within your own custom projects.

For complete details and instructions on installing and getting started with the Aeris iOS Weather SDK, refer to our complete [usage and API documentation](http://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk/).

## Need Support?

Feel free to [submit a new ticket](http://helpdesk.aerisweather.com/) with any questions, bug reports or feature suggestions you have. You can also reach out to us on Twitter at [@AerisDeveloper](https://twitter.com/AerisDeveloper).

![image](http://www.aerisweather.com/img/docs/ios/docs-ios-screen-wxmap01.png)
![image](http://www.aerisweather.com/img/docs/ios/docs-ios-screen-wxviews01.png)