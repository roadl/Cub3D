## Project Overview
> 42 Seoul 3D Graphics Subject

Ray Casting을 이용해 3D 1인칭 화면 구현 프로젝트입니다


## Features
- Ray Casting 기반 3D 1인칭 시점 렌더링
  - DDA 알고리즘을 이용한 Ray Casting
  - Fish-Eye 효과 처리
- 벽 충돌 판정 및 이동 처리
- 방향별 텍스쳐 렌더링
  - UV 좌표 기반 픽셀 매핑
- .cub 맵 파싱 및 유효성 검사
- 키 입력 이벤트 처리
- 잘못된 입력 또는 맵 오류에 따른 에러 처리

## Controls
- W / A / S / D : 이동

- ← / → : 시점 회전

- ESC : 종료

## Build & Run
For Mac OS

```
git clone https://github.com/roadl/Cub3D.git cub3D
cd cub3D
make
./cub3D map/validmap1.cub
```

validmap1.cub 대신 원하는 .cub 파일을 사용할 수 있습니다.

## Map Format
.cub: 텍스처 정보, 바닥/하늘 색상 정보, 맵 정보로 구성

1. 텍스처 경로

   각 방향의 벽 텍스처 지정
   ```
   NO ./textures/north.xpm
   SO ./textures/south.xpm
   WE ./textures/west.xpm
   EA ./textures/east.xpm
   ```
   
2. 바닥/천장 색상

   F - Floor, C - Ceiling, RGB로 지정
   ```
   F 220,100,0
   C 225,30,0
   ```
   
3. 맵 구성

   1: 벽, 0: 빈 공간, N/S/E/W: 플레이어 시작 위치 및 방향

   맵은 반드시 벽으로 둘러싸여 있어야 함

   플레이어는 반드시 1명 존재
   ```
   111111
   100001
   10N001
   100001
   111111
   ```

## Development Enviroment
- OS: Sonoma 14.5
- Architecture: arm64 (Apple Silicon)
- Language: C (C99)
- Compiler: clang (Apple clang 15.0.0)
- Graphic Library: MinilibX
- Frameworks: OpenGL, AppKit
- Build Tool: make

## Team Members
[roadl](github.com/roadl) 
[yuyunjae](github.com/yuyunjae)
