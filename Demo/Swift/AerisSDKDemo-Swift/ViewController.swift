//
//  ViewController.swift
//  AerisSDKDemo-Swift
//
//  Created by Nicholas Shipes on 7/20/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
	
	var weatherMap: AWFWeatherMap!

	override func viewDidLoad() {
		super.viewDidLoad()
		
		weatherMap = AWFWeatherMap(mapType: .apple)
		weatherMap.weatherMapView.frame = view.bounds
		view.addSubview(weatherMap.weatherMapView)
	}
	
	override func viewDidAppear(_ animated: Bool) {
		super.viewDidAppear(animated)
		
		weatherMap.add(.typeRadar)
	}

	override func didReceiveMemoryWarning() {
		super.didReceiveMemoryWarning()
		// Dispose of any resources that can be recreated.
	}


}

