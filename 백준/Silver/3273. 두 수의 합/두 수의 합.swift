import Foundation

let n = Int(readLine()!)!
let array = readLine()!.split(separator: " ").map { Int($0)! }
let x = Int(readLine()!)!

var answer = 0
var d: [Bool] = .init(repeating: false, count: 2000002)

for element in array {
    d[element] = true
}

for element in array {
    if element < x && d[x - element] { answer += 1}
}

print(answer / 2)