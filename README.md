AerisWeather iOS SDK 3.0
=============

The [AerisWeather SDK for iOS](https://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk-3/) allows a developer to quickly and easily add weather content and functionality to their iOS applications quickly and easily without having to code anything themselves. It utilizes the [Aeris Weather API](http://www.aerisweather.com/support/docs/api/) and [Aeris Maps Platform (AMP)](http://www.aerisweather.com/support/docs/maps/) backends for weather data and imagery and makes integrating your application with your Aeris Weather account considerably easier and more efficient.

## Aeris Modules

The AerisWeather SDK is broken up into multiple modules, allowing you to only include the components you need. However, some of the components have dependencies on one or more of the others as it simple builds upon them. 

* **AerisWeatherKit.framework** - Core weather library used to interact with and parse Aeris Weather API data.
	* requires the core *AerisCore* and *AerisCoreUI* modules that are also distributed with the SDK. 
* **AerisMapKit.framework** - Complete interactive weather map solution utilizing the Aeris Maps (AMP) API.
	* requires AerisWeatherKit.framework
* **AerisMapboxMapKit.framework** - Extension of the AerisMapKit module to support the Mapbox iOS SDK
	* requires AerisWeatherKit.framework, AerisMapKit.framework
	* requires [Mapbox iOS SDK](https://www.mapbox.com/ios-sdk/)
* **AerisGoogleMapKit.framework** - Extension of the AerisMapKit module to support using the Google Maps SDK.
	* requires AerisWeatherKit.framework, AerisMapKit.framework
	* requires [Google Maps SDK](https://developers.google.com/maps/documentation/ios-sdk/)
	
## Setup

We have in-depth [installation](https://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk-3/getting-started/installation/) and [setup](https://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk-3/getting-started/setup/) guides available for you to get started using the Aeris Weather SDK for iOS. 

The following are basic installation instructions to follow to get the SDK integrated with your project based on your desired method. Select one of the following methods to integrate the SDK based on your preferred method, but don't use more than one method as that will result in duplicate copies of the SDK and compiler errors.

### CocoaPods
1. Make sure you have CocoaPods installed and working. If you don't have CocoaPods installed on your system, follow the [installation instructions](https://guides.cocoapods.org/using/getting-started.html) to get started. If you're new to or unfamiliar with CocoaPods, also make sure to review its [usage guide](https://guides.cocoapods.org/using/using-cocoapods.html) to learn more about how to get started with CocoaPods for your project.
2. Add the `AerisWeather` pod to your `Podfile`. This will add the base AerisWeatherKit.framework and its core dependencies to your project.
	
	```ruby
	pod 'AerisWeather'
	```
	
3. If you want to also use any of the weather mapping functionality available in our iOS SDK, you'll need to also include the `Maps` pod:

	```ruby
	pod 'AerisWeather/Maps'
	
	# include this if using Mapbox for maps in your project
	pod 'AerisWeather/Mapbox'
	
	# or include this if using Google Maps for maps in your project
	pod 'AerisWeather/GoogleMaps'
	```
		
4. Run `pod install` from the Terminal at the root of your project where your `Podfile` is located.
5. Open your `*.xcworkspace` with Xcode and follow our [setup guide](https://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk-3/getting-started/setup/) to start using the SDK. **Note:** Do NOT use `*.xcodeproj` as you'll receive `ld: library not found` errors for the Aeris Weather SDK libraries.

### Carthage
1. Install the latest version of [Carthage](https://github.com/Carthage/Carthage#installing-carthage).
2. Add the following to your `Cartfile`:
	
	```ruby
	github ....
	```

3. Run `carthage update`.
4. With your project open in Xcode, select your **Target**. Under the **General** tab, find **Embedded Binaries** and then click the **+** button.
5. Click the **Add Other...** button, navigate to the `Aeris###`.framework` files under **Carthage > Build > iOS** and select them. Do NOT check the **Destination: Copy items if needed** checkbox when prompted.
6. Under the **Build Phases* tab of your **Target**, click the **+** button on the top-left and select **New Run Script Phase**. Setup the build phase as follows, and make sure this phase is below the **Embed Frameworks** phase:

	```sh
	Shell /bin/sh
	
	bash "${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/AerisCore.framework/strip-frameworks.sh"
	
	Show environment variables in build log: Checked
	Run script only when installing: Not checked
	
	Input Files: Empty
	Output Files: Empty
	```
		
7. Follow our [setup guide](https://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk-3/getting-started/setup/) to start using the SDK.

### Dynamic Frameworks
1. Download the SDK from our [Github repository](https://github.com/aerisweather/Aeris-iOS-Library) that also contains our demo application. The repo will contain a compressed file archive for you to download.
2. With your project open in Xcode, select your **Target**. Under the **General** tab, find **Embedded Binaries** and then click the **+** button.
3. Click the **Add Other...** button, navigate to the `Aeris###`.framework` files under **Carthage > Build > iOS** and select them. Make sure to check the **Destination: Copy items if needed** checkbox when prompted.
4. Under the **Build Phases* tab of your **Target**, click the **+** button on the top-left and select **New Run Script Phase**. Setup the build phase as follows, and make sure this phase is below the **Embed Frameworks** phase:

	```sh
	Shell /bin/sh
	
	bash "${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/AerisCore.framework/strip-frameworks.sh"
	
	Show environment variables in build log: Checked
	Run script only when installing: Not checked
	
	Input Files: Empty
	Output Files: Empty
	```
		
5. Follow our [setup guide](https://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk-3/getting-started/setup/) to start using the SDK.

## Demo Application

Check out the included demo project, under the **Demo** directory, which contains a variety of example views using different components of the SDK, including pre-built weather views and weather maps utilizing different mapping libraries. Since the project's Aeris Weather SDK dependencies in the demo project are installed and managed using [CocoaPods](http://cocoapods.org), you will need to open the **Demo/AerisDemo.xcworkspace**.

The various frameworks of the Aeris iOS Weather SDK are located under the **SDK** directory. These are the libraries you will be using within your own custom projects.

For complete details and instructions on installing and getting started with the Aeris iOS Weather SDK, refer to our complete [Getting Started and API documentation](https://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk-3/getting-started/).

## Need Support?

Feel free to [submit a new ticket](http://helpdesk.aerisweather.com/) with any questions, bug reports or feature suggestions you have. You can also reach out to us on Twitter at [@AerisDeveloper](https://twitter.com/AerisDeveloper).

![image](http://www.aerisweather.com/img/docs/ios/docs-ios-screen-wxmap01.png)
![image](http://www.aerisweather.com/img/docs/ios/docs-ios-screen-wxviews01.png)