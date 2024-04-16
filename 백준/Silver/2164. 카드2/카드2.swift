import Foundation

struct QueuePointer<T> {
    private var elements: [T] = []
    private var front = 0
    
    var isEmpty: Bool {
        elements.count < front + 1
    }
    
    var count: Int {
        elements.count - front
    }
    
    func peek() -> T? {
        front < elements.count ? elements[front] : nil
    }
    
    mutating func enqueue(with element: T) {
        elements.append(element)
    }
    
    @discardableResult
    mutating func dequeue() -> T? {
        if !isEmpty {
            defer { front += 1 }
            return elements[front]
        } else {
            return nil
        }
    }
}

let N = Int(readLine()!)!
var queue = QueuePointer<Int>()

for i in 1...N {
    queue.enqueue(with: i)
}

while queue.count > 1 {
    queue.dequeue()
    let front = queue.dequeue()!
    queue.enqueue(with: front)
}

print(queue.peek()!)