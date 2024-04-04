import Foundation

var n = Int(readLine()!)!
var array = readLine()!.split(separator: " ").map { Int($0)! }
var x = Int(readLine()!)!

var dict: [Int: Void] = [:]
var count = 0

for i in array {
    dict.updateValue((), forKey: i)
}

for i in array {
    if let j = dict[x - i] { count += 1 }
}

print(count / 2)