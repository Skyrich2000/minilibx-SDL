# minilibx-sdl

costom minilibx made with SDL 2.0 by ycha

## issue

* 키를 꾹 누르면 계속 KEY_DOWN 이벤트가 발생함
- 이미지
    - Surface
        - pixel 얻기 쉬움
        - software render
    - Texture
        - pixel 얻기 어려움
        - hardware render
    - Surface + Texture
        - 출력할때마다 vram 으로 올리는 짓 해야댐