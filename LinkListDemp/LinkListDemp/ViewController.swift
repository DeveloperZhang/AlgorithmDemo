//
//  ViewController.swift
//  LinkListDemp
//
//  Created by Vicent on 2019/1/8.
//  Copyright © 2019 VicentZ. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        testAction((Any).self)
        testAction1(sender: (Any).self)
    }

    @IBAction func testAction(_ sender: Any) {
        testLinkList()
    }
    
    func testAction1(sender: Any){}
    
}

