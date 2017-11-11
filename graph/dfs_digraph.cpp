t e m p l a t e   < t y p e n a m e   T >  
 c l a s s   d f s _ d i g r a p h   :   p u b l i c   d i g r a p h < T >   {  
     p u b l i c :  
     u s i n g   d i g r a p h < T > : : e d g e s ;  
     u s i n g   d i g r a p h < T > : : g ;  
     u s i n g   d i g r a p h < T > : : n ;  
     u s i n g   d i g r a p h < T > : : i g n o r e ;  
  
     v e c t o r < i n t >   p v ;  
     v e c t o r < i n t >   p e ;  
     v e c t o r < i n t >   o r d e r ;  
     v e c t o r < i n t >   p o s ;  
     v e c t o r < i n t >   e n d ;  
     v e c t o r < i n t >   s z ;  
     v e c t o r < i n t >   r o o t ;  
     v e c t o r < i n t >   d e p t h ;  
     v e c t o r < T >   d i s t ;  
  
     d f s _ d i g r a p h ( i n t   _ n )   :   d i g r a p h < T > ( _ n )   {  
     }  
  
     v o i d   c l e a r ( )   {  
         p v . c l e a r ( ) ;  
         p e . c l e a r ( ) ;  
         o r d e r . c l e a r ( ) ;  
         p o s . c l e a r ( ) ;  
         e n d . c l e a r ( ) ;  
         s z . c l e a r ( ) ;  
         r o o t . c l e a r ( ) ;  
         d e p t h . c l e a r ( ) ;  
         d i s t . c l e a r ( ) ;  
     }  
  
     v o i d   i n i t ( )   {  
         p v   =   v e c t o r < i n t > ( n ,   - 1 ) ;  
         p e   =   v e c t o r < i n t > ( n ,   - 1 ) ;  
         o r d e r . c l e a r ( ) ;  
         p o s   =   v e c t o r < i n t > ( n ,   - 1 ) ;  
         e n d   =   v e c t o r < i n t > ( n ,   - 1 ) ;  
         s z   =   v e c t o r < i n t > ( n ,   0 ) ;  
         r o o t   =   v e c t o r < i n t > ( n ,   - 1 ) ;  
         d e p t h   =   v e c t o r < i n t > ( n ,   - 1 ) ;  
         d i s t   =   v e c t o r < T > ( n ) ;  
     }  
  
     p r i v a t e :  
     v o i d   d o _ d f s ( i n t   v )   {  
         p o s [ v ]   =   ( i n t )   o r d e r . s i z e ( ) ;  
         o r d e r . p u s h _ b a c k ( v ) ;  
         s z [ v ]   =   1 ;  
         f o r   ( i n t   i d   :   g [ v ] )   {  
             i f   ( i d   = =   p e [ v ]   | |   ( i g n o r e   ! =   n u l l p t r   & &   i g n o r e ( i d ) ) )   {  
                 c o n t i n u e ;  
             }  
             a u t o   & e   =   e d g e s [ i d ] ;  
             i n t   t o   =   e . f r o m   ^   e . t o   ^   v ;  
             / /   w e l l ,   t h i s   i s   c o n t r o v e r s i a l . . .  
             i f   ( d e p t h [ t o ]   ! =   - 1 )   {  
                 c o n t i n u e ;  
             }  
             d e p t h [ t o ]   =   d e p t h [ v ]   +   1 ;  
             d i s t [ t o ]   =   d i s t [ v ]   +   e . c o s t ;  
             p v [ t o ]   =   v ;  
             p e [ t o ]   =   i d ;  
             r o o t [ t o ]   =   r o o t [ v ] ;  
             d o _ d f s ( t o ) ;  
             s z [ v ]   + =   s z [ t o ] ;  
         }  
         e n d [ v ]   =   ( i n t )   o r d e r . s i z e ( )   -   1 ;  
     }  
  
     v o i d   d o _ d f s _ f r o m ( i n t   v )   {  
         d e p t h [ v ]   =   0 ;  
         d i s t [ v ]   =   T { } ;  
         r o o t [ v ]   =   v ;  
         p v [ v ]   =   p e [ v ]   =   - 1 ;  
         d o _ d f s ( v ) ;  
     }  
  
     p u b l i c :  
     i n t   d f s _ o n e _ u n s a f e ( i n t   v )   {  
         / /   r u n   i n i t ( )   b e f o r e   t h i s  
         / /   t h e n   r u n   t h i s   w i t h   t h e   r e q u i r e d   v ' s  
         d o _ d f s _ f r o m ( v ) ;  
         r e t u r n   v ;  
     }  
  
     i n t   d f s ( i n t   v )   {  
         i n i t ( ) ;  
         d o _ d f s _ f r o m ( v ) ;  
 / /         a s s e r t ( ( i n t )   o r d e r . s i z e ( )   = =   n ) ;  
         r e t u r n   v ;  
     }  
  
     v o i d   d f s _ m a n y ( c o n s t   v e c t o r < i n t >   & r o o t s )   {  
         i n i t ( ) ;  
         f o r   ( i n t   v   :   r o o t s )   {  
             i f   ( d e p t h [ v ]   = =   - 1 )   {  
                 d o _ d f s _ f r o m ( v ) ;  
             }  
         }  
 / /         a s s e r t ( ( i n t )   o r d e r . s i z e ( )   = =   n ) ;  
     }  
  
     v e c t o r < i n t >   d f s _ a l l ( )   {  
         i n i t ( ) ;  
         v e c t o r < i n t >   r o o t s ;  
         f o r   ( i n t   v   =   0 ;   v   <   n ;   v + + )   {  
             i f   ( d e p t h [ v ]   = =   - 1 )   {  
                 r o o t s . p u s h _ b a c k ( v ) ;  
                 d o _ d f s _ f r o m ( v ) ;  
             }  
         }  
         a s s e r t ( ( i n t )   o r d e r . s i z e ( )   = =   n ) ;  
         r e t u r n   r o o t s ;  
     }  
 } ; 