(define (hello x)
  (if (= 0 x)
      666
      (hello (- x 1))
      )
  )
(define (main)
  (display (null? 'a))
  (display (char? 'ab))
  (display (hello 5))
)
