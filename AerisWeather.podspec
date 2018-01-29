Pod::Spec.new do |s|
  s.name         = 'AerisWeather'
  s.version      = '3.0.0-beta.1'
  s.summary      = 'Quickly integrate the Aeris Weather API data and map overlays into your iOS apps.'
  s.description  = <<-DESC
                      The Aeris iOS Weather Framework allows a developer to quickly and easily add weather content and functionality to their iOS applications quickly and easily without having to code anything themselves. It utilizes the Aeris API backend for data loading and is built on top of an object mapping system that efficiently loads requested weather content into third-party iOS applications, greatly reducing the amount of code and development needed on the developer end.
                    DESC

  s.homepage     = 'https://github.com/aerisweather/Aeris-iOS-Library'
  s.documentation_url = 'http://www.aerisweather.com/support/docs/toolkits/aeris-ios-sdk/'
  s.social_media_url = 'https://twitter.com/AerisDeveloper'
  s.license      = { :type => 'BSD', :file => 'LICENSE' }
  s.author       = { 'AerisWeather, LLC' => 'http://aerisweather.com' }
  s.source       = { :git => 'https://github.com/aerisweather/Aeris-iOS-Library.git', :tag => s.version.to_s }

  s.platform     = :ios, '9.0'
  s.requires_arc = true
  s.default_subspecs = 'Data'


  s.subspec 'Core' do |ss|
    ss.header_dir = 'AerisCore'
    ss.vendored_frameworks = 'SDK/AerisCore.framework'
    ss.framework = 'Foundation'
  end

  s.subspec 'CoreUI' do |ss|
    ss.header_dir = 'AerisCoreUI'
    ss.vendored_frameworks = 'SDK/AerisCoreUI.framework'
    ss.framework = 'UIKit'
  end

  s.subspec 'Data' do |ss|
    ss.header_dir = 'AerisWeatherKit'
    ss.vendored_frameworks = 'SDK/AerisWeatherKit.framework'
    ss.resource_bundle = {
      # 'Aeris' => ['SDK/AerisWeatherKit.bundle/*']
    }
    ss.framework = "UIKit"
  end

  s.subspec 'Maps' do |ss|
    ss.header_dir = 'AerisMapKit'
    ss.vendored_frameworks = 'SDK/AerisMapKit.framework'
    ss.framework = 'MapKit'
    ss.dependency 'AerisWeather/CoreUI'
  end

  s.subspec 'Mapbox' do |ss|
    ss.header_dir = 'AerisMapboxMapKit'
    ss.vendored_frameworks = 'SDK/AerisMapboxMapKit.framework'
    ss.dependency 'Mapbox-iOS-SDK'
    ss.dependency 'AerisWeather/Maps'
  end

  s.subspec 'Google' do |ss|
    ss.header_dir = 'AerisGoogleMapKit'
    ss.vendored_frameworks = 'SDK/AerisGoogleMapKit.framework'
    ss.dependency 'GoogleMaps'
    ss.dependency 'AerisWeather/Maps'
  end

end
