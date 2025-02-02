FasdUAS 1.101.10   ��   ��    k             l     ����  O       	  k     
 
     l   ��  ��    ] W get the path of the _folder_ containing this application. This is kinda tricky because     �   �   g e t   t h e   p a t h   o f   t h e   _ f o l d e r _   c o n t a i n i n g   t h i s   a p p l i c a t i o n .   T h i s   i s   k i n d a   t r i c k y   b e c a u s e      l   ��  ��    X R we have to ask the finder for this particular "application file id", rather than      �   �   w e   h a v e   t o   a s k   t h e   f i n d e r   f o r   t h i s   p a r t i c u l a r   " a p p l i c a t i o n   f i l e   i d " ,   r a t h e r   t h a n        l   ��  ��    %  just asking for "my" location.     �   >   j u s t   a s k i n g   f o r   " m y "   l o c a t i o n .   ��  r        l    ����  n        1    ��
�� 
psxp  l     ����   c     ! " ! n     # $ # m   	 ��
�� 
ctnr $ l   	 %���� % 5    	�� &��
�� 
appf & m     ' ' � ( ( N c o m . a p p l e . S c r i p t E d i t o r . i d . A u t h o r i z e - X P L
�� kfrmID  ��  ��   " m    ��
�� 
alis��  ��  ��  ��    o      ���� 0 current_path  ��   	 m      ) )�                                                                                  MACS  alis    @  Macintosh HD                   BD ����
Finder.app                                                     ����            ����  
 cu             CoreServices  )/:System:Library:CoreServices:Finder.app/    
 F i n d e r . a p p    M a c i n t o s h   H D  &System/Library/CoreServices/Finder.app  / ��  ��  ��     * + * l     ��������  ��  ��   +  , - , l     �� . /��   . h b Okay, current_path should be the folder containing this script: display to user for confirmation.    / � 0 0 �   O k a y ,   c u r r e n t _ p a t h   s h o u l d   b e   t h e   f o l d e r   c o n t a i n i n g   t h i s   s c r i p t :   d i s p l a y   t o   u s e r   f o r   c o n f i r m a t i o n . -  1 2 1 l    3���� 3 I   �� 4��
�� .sysodlogaskr        TEXT 4 b     5 6 5 m     7 7 � 8 8 H A u t h o r i z i n g   M a c   * . x p l   p l u g i n s   i n :   
 
 6 o    ���� 0 current_path  ��  ��  ��   2  9 : 9 l     ��������  ��  ��   :  ; < ; l     �� = >��   = R L Now, It's an error to delete xattr, if the file doesn't contain that xattr.    > � ? ? �   N o w ,   I t ' s   a n   e r r o r   t o   d e l e t e   x a t t r ,   i f   t h e   f i l e   d o e s n ' t   c o n t a i n   t h a t   x a t t r . <  @ A @ l     �� B C��   B L F So, first see if the file has _any_ xattr. If it doesn't we'll assume    C � D D �   S o ,   f i r s t   s e e   i f   t h e   f i l e   h a s   _ a n y _   x a t t r .   I f   i t   d o e s n ' t   w e ' l l   a s s u m e A  E F E l     �� G H��   G M G it's the correct xattr. (If you run the script twice on the same file,    H � I I �   i t ' s   t h e   c o r r e c t   x a t t r .   ( I f   y o u   r u n   t h e   s c r i p t   t w i c e   o n   t h e   s a m e   f i l e , F  J K J l     �� L M��   L M G it would otherwise error on second execution. This is really all we're    M � N N �   i t   w o u l d   o t h e r w i s e   e r r o r   o n   s e c o n d   e x e c u t i o n .   T h i s   i s   r e a l l y   a l l   w e ' r e K  O P O l     �� Q R��   Q !  protecting ourselves from.    R � S S 6   p r o t e c t i n g   o u r s e l v e s   f r o m . P  T U T l   P V���� V Q    P W X Y W k    1 Z Z  [ \ [ r    ) ] ^ ] I   '�� _��
�� .sysoexecTEXT���     TEXT _ b    # ` a ` b    ! b c b m     d d � e e  c d   ' c o     ���� 0 current_path   a m   ! " f f � g g 2 ' ;   x a t t r   - l   m a c _ x 6 4 / * . x p l��   ^ o      ���� 0 
the_result   \  h�� h r   * 1 i j i I  * /�� k��
�� .corecnte****       **** k o   * +���� 0 
the_result  ��   j o      ���� 0 
the_length  ��   X R      �� l m
�� .ascrerr ****      � **** l o      ���� 
0 errmsg   m �� n��
�� 
errn n o      ���� 0 errorno  ��   Y k   9 P o o  p q p l  9 9�� r s��   r T N oops, we got an error. Most commonly, it's because we can't find the xpl file    s � t t �   o o p s ,   w e   g o t   a n   e r r o r .   M o s t   c o m m o n l y ,   i t ' s   b e c a u s e   w e   c a n ' t   f i n d   t h e   x p l   f i l e q  u v u l  9 9�� w x��   w 0 * Nothing more we can do, so report & quit.    x � y y T   N o t h i n g   m o r e   w e   c a n   d o ,   s o   r e p o r t   &   q u i t . v  z { z I  9 J�� | }
�� .sysodlogaskr        TEXT | b   9 > ~  ~ m   9 < � � � � �4 E R R O R :   C o u l d   n o t   f i n d   a n y   M a c   X P L   f i l e s . 
 	 
 M o v e   t h i s   s c r i p t   i n t o   t h e   f o l d e r   f o r   t h e   p l u g i n   y o u   w h i c h   t o 
 a u t h o r i z e . . .   < X - P l a n e > / R e s o u r c e s / p l u g i n s / X X X X X / 	 
 
  o   < =���� 
0 errmsg   } �� ���
�� 
btns � J   A F � �  ��� � m   A D � � � � �  Q u i t��  ��   {  ��� � I  K P������
�� .aevtquitnull��� ��� null��  ��  ��  ��  ��   U  � � � l     ��������  ��  ��   �  � � � l     �� � ���   � K E Okay, found a file. Rather than try to actually read the found xattr    � � � � �   O k a y ,   f o u n d   a   f i l e .   R a t h e r   t h a n   t r y   t o   a c t u a l l y   r e a d   t h e   f o u n d   x a t t r �  � � � l     �� � ���   � G A just check to see if anything exists. Here, but simply seeing if    � � � � �   j u s t   c h e c k   t o   s e e   i f   a n y t h i n g   e x i s t s .   H e r e ,   b u t   s i m p l y   s e e i n g   i f �  � � � l     �� � ���   � 5 / the length is greater than some small amount.     � � � � ^   t h e   l e n g t h   i s   g r e a t e r   t h a n   s o m e   s m a l l   a m o u n t .   �  � � � l     �� � ���   � L F If the length is too small, then it's clearly not the attribute we're    � � � � �   I f   t h e   l e n g t h   i s   t o o   s m a l l ,   t h e n   i t ' s   c l e a r l y   n o t   t h e   a t t r i b u t e   w e ' r e �  � � � l     �� � ���   � 9 3 looking for (perhaps already deleted?) so skip it.    � � � � f   l o o k i n g   f o r   ( p e r h a p s   a l r e a d y   d e l e t e d ? )   s o   s k i p   i t . �  � � � l  Q h ����� � Z   Q h � ����� � l  Q T ����� � ?   Q T � � � o   Q R���� 0 
the_length   � m   R S���� ��  ��   � k   W d � �  � � � l  W W�� � ���   � . ( Look good, attempt to remove quarantine    � � � � P   L o o k   g o o d ,   a t t e m p t   t o   r e m o v e   q u a r a n t i n e �  ��� � I  W d�� ���
�� .sysoexecTEXT���     TEXT � b   W ` � � � b   W \ � � � m   W Z � � � � �  c d   ' � o   Z [���� 0 current_path   � m   \ _ � � � � � \ ' ;   x a t t r   - d   c o m . a p p l e . q u a r a n t i n e   m a c _ x 6 4 / * . x p l��  ��  ��  ��  ��  ��   �  � � � l     ��������  ��  ��   �  � � � l     ��������  ��  ��   �  � � � l     �� � ���   � G A XPPython3 includes (at least) one shared object, which will also    � � � � �   X P P y t h o n 3   i n c l u d e s   ( a t   l e a s t )   o n e   s h a r e d   o b j e c t ,   w h i c h   w i l l   a l s o �  � � � l     �� � ���   �    be subject to quarantine.    � � � � 4   b e   s u b j e c t   t o   q u a r a n t i n e . �  � � � l     �� � ���   � L F Repeat the process, but this time, if we don't find the shared object    � � � � �   R e p e a t   t h e   p r o c e s s ,   b u t   t h i s   t i m e ,   i f   w e   d o n ' t   f i n d   t h e   s h a r e d   o b j e c t �  � � � l     �� � ���   � J D dont complain: This way, this script can actually be used for _ANY_    � � � � �   d o n t   c o m p l a i n :   T h i s   w a y ,   t h i s   s c r i p t   c a n   a c t u a l l y   b e   u s e d   f o r   _ A N Y _ �  � � � l     �� � ���   � K E X-Plane XPL plugin! Just move/copy the script into the next plugin's    � � � � �   X - P l a n e   X P L   p l u g i n !   J u s t   m o v e / c o p y   t h e   s c r i p t   i n t o   t h e   n e x t   p l u g i n ' s �  � � � l     �� � ���   �    folder and re-execute it.    � � � � 4   f o l d e r   a n d   r e - e x e c u t e   i t . �  � � � l  i � ����� � Q   i � � � � � k   l � � �  � � � r   l { � � � I  l y�� ���
�� .sysoexecTEXT���     TEXT � b   l u � � � b   l q � � � m   l o � � � � �  c d   ' � o   o p���� 0 current_path   � m   q t � � � � � 8 ' ;   x a t t r   - l   i m g u i / * d a r w i n . s o��   � o      ���� 0 
the_result   �  ��� � r   | � � � � I  | ��� ���
�� .corecnte****       **** � o   | }���� 0 
the_result  ��   � o      ���� 0 
the_length  ��   � R      ������
�� .ascrerr ****      � ****��  ��   � k   � � � �  � � � r   � � � � � m   � �����   � o      ���� 0 
the_length   �  ��� � l  � ��� � ���   �   silently ignore error    � � � � ,   s i l e n t l y   i g n o r e   e r r o r��  ��  ��   �  � � � l  � � ����  Z   � ����� l  � ����� ?   � � o   � ����� 0 
the_length   m   � ����� ��  ��   I  � �����
�� .sysoexecTEXT���     TEXT b   � � b   � �	
	 m   � � �  c d   '
 o   � ����� 0 current_path   m   � � � b ' ;   x a t t r   - d   c o m . a p p l e . q u a r a n t i n e   i m g u i / * d a r w i n . s o��  ��  ��  ��  ��   �  l     ��������  ��  ��    l     ��   %  we're done: let the user know!    � >   w e ' r e   d o n e :   l e t   t h e   u s e r   k n o w ! �~ l  � ��}�| I  � ��{
�{ .sysodlogaskr        TEXT m   � � �  S u c c e s s �z�y
�z 
btns J   � � �x m   � � �    O k a y�x  �y  �}  �|  �~       �w!"#$�v�w  ! �u�t�s�r
�u .aevtoappnull  �   � ****�t 0 current_path  �s 0 
the_result  �r 0 
the_length  " �q%�p�o&'�n
�q .aevtoappnull  �   � ****% k     �((  ))  1**  T++  �,,  �--  �.. �m�m  �p  �o  & �l�k�l 
0 errmsg  �k 0 errorno  '   )�j '�i�h�g�f�e 7�d d f�c�b�a�`�_/ ��^ ��] � � � ��\�[
�j 
appf
�i kfrmID  
�h 
ctnr
�g 
alis
�f 
psxp�e 0 current_path  
�d .sysodlogaskr        TEXT
�c .sysoexecTEXT���     TEXT�b 0 
the_result  
�a .corecnte****       ****�` 0 
the_length  �_ 
0 errmsg  / �Z�Y�X
�Z 
errn�Y 0 errorno  �X  
�^ 
btns
�] .aevtquitnull��� ��� null�\  �[  �n �� *���0�,�&�,E�UO��%j 	O ��%�%j E�O�j E�W X  a �%a a kvl 	O*j O�m a �%a %j Y hO a �%a %j E�O�j E�W X  jE�OPO�m a �%a %j Y hOa a a kvl 	# �00 B / U s e r s / p b u c k / D o w n l o a d s / X P P y t h o n 3 /$ �11  �v   ascr  ��ޭ