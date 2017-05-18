
(define (literal_ident_return return_me_please)
  return_me_please
  )

(define (literal_quotedlit_return)
  6
  )

(define (returns_number)
  666
  )

(define (opraw t)
  (display t)
)

(define (cons_test t)
  (cons t t)
  )

(define (predicate_test t)
  (if (null? t)
      (zero? t)
      (if (char? t)
	  (string? t)
	  (symbol? t)
	  )
      )
  )

(define (not_test t)
  (if (not (null? t))
      (not (char? t))
      (not (list? t))
      )
  )

(define (add_test)
  (+ (+ 10 20) (+ 7 8))
  )

(define (arith_test)
  (+ (+ (*2 2) 4) (*3 5))
  )

(define (subdiv_test)
  (- 5 4)
  )

(define (comparative_test)
  (if (>= 5 4)
      (if (<= 1 2)
	  (< 5 4)
	  (> 1 2)
	  )
      (* 1 2)
      )
  )

(define (logical_test x y z)
  (if (and (null? x) (null? y))
      (or  (null? x) (and (null? y) (null? z)))
      1
      )
  )
(define (main)
  (display (not_test 5))
  (display (add_test))
  (display (arith_test))
  (display (subdiv_test))
  )
