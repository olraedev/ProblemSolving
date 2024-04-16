import Foundation

struct Stack<T> {
    private var elements: [T] = []
    init() {}
    
    // O(1)
    mutating func push(with element: T ) {
        elements.append(element)
    }
    
    // O(1)
    mutating func pop() -> T? {
        elements.popLast()
    }
    
    // O(1)
    func peek() -> T? {
        elements.last
    }
    
    var isEmpty: Bool {
        elements.isEmpty
    }
    
    var count: Int {
        elements.count
    }
}

let N = Int(readLine()!)!

for _ in 0..<N {
    var flag = true
    let input = readLine()!.map { String($0) }
    var stack = Stack<String>()
    
    for i in 0...input.count - 1 {
        if input[i] == "(" {
            stack.push(with: input[i])
        }
        else {
            guard let _ = stack.pop() else {
                flag = false
                break
            }
        }
    }
    if flag {
        if stack.isEmpty { print("YES") }
        else { print("NO") }
    }
    else { print("NO") }
}