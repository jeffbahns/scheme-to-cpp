
;(define (literal_ident_return return_me_please)
;  return_me_please
;  )

;(define (literal_quotedlit_return)
;  (if 0
;      5
;      6
;  )

;(define (returns_number)
;  666
;  )

;(define (opraw t)
;  (display t)
;)

;(define (cons_test t)
;  (if (cons t t)
;      (cons t t)
;      (if (car t)
;	  666
;	  666666
;	  )
;      )
;  )


(define (predicate_test t)
  (if (null? t)
      (zero? t)
      (if (char? t)
	  (string? t)
	  (symbol? t)
	  )
      )
  )

(define (main)
  0
  )
