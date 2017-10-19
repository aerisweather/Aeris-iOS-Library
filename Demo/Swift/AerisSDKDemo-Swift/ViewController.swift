//
//  ViewController.swift
//  AerisSDKDemo-Swift
//
//  Created by Nicholas Shipes on 7/20/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

import UIKit

class ViewController: AWFWeatherMapViewController {
	
//	var weatherMap: AWFWeatherMap!
	
	override func viewDidLoad() {
		super.viewDidLoad()
		
//		view.backgroundColor = UIColor.white
//
//		weatherMap = AWFWeatherMap(mapType: .apple)
//		weatherMap.weatherMapView.frame = view.bounds
//		view.addSubview(weatherMap.weatherMapView)
		
//		weatherMap.config.timelineEndOffsetFromNow = 3600 * 2;
//		weatherMap.timelineEndDate = Date().addingTimeInterval(3600 * 2)
	}
	
	override func viewDidAppear(_ animated: Bool) {
		super.viewDidAppear(animated)
		
//		weatherMap.add(.typeRadar)
		weatherMap.add(.typeFutureRainHRRR)
		weatherMap.add(.typeFuturePrecipNAM4K)
		weatherMap.add(.typeFuturePrecip)
		weatherMap.add(.typeFutureRain)
		weatherMap.add(.typeFutureRainGFS)
		weatherMap.add(.typeFutureTemperaturesGFS)
		
	}

	override func didReceiveMemoryWarning() {
		super.didReceiveMemoryWarning()
		// Dispose of any resources that can be recreated.
	}


}

