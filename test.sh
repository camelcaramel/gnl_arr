#!/bin/bash

# 이거를 프로젝트 폴더로 수정하세요!
PROJ_PATH=.

# ### 안내사항
# 1. https://github.com/PandaCoustik/Test-42
# 에 나와있는 gnl 테스트 및 기타 테스트들에 대하여 자동으로 실행시켜주는 스크립트입니다.
# 2. 각 테스터마다 주석으로 제목이 달려있으며, 하나의 블록을 통째로 주석처리하여 테스터 실행을 건너뛸 수 있습니다.
# 3. 2021.01.24 기준으로 작동되지만, 추후 정상적으로 작동하지 않을 수 있습니다.
# 4. 본 테스트는 보너스가 구현된 환경에서만 동작되었습니다.
# 5. 테스트의 결과는 각 테스터마다 다르게 출력되므로, 직접 테스터기의 스크립트나 코드를 확인하여 출력 결과의 의미가 무엇인지 직접 확인하시는 게 좋습니다.

# ### 주의사항
# 1. 작동 환경에 따라 예상치 못한 동작이 발생할 수 있습니다.. 반드시 git push 해두시기 바랍니다.
# 2. 본 스크립트는 프로젝트 폴더 내에 테스트 폴더를 생성합니다.
# 3. 테스트 완료후 테스트 폴더/파일이 삭제되지 않습니다.

# ### 대략적인 스크립트의 원리 ### ---------------------
# 1. 테스트를 git clone 합니다.
# 2. 테스트 폴더로 들어가 테스트를 수행하고 밖으로 빠져나옵니다.

# ----------------------------------------
# ###### gitignore 하면 편한 것들 ######
# 42testers-gnl/
# gnl-lover/
# gnlkiller/
# gnlkiller2/
# Test-42/
# gnlTester/
# ----------------------------------------

# 실제 프로젝트 폴더 위치로 이동
REAL_PATH=$(cd $(dirname $0) && cd ${PROJ_PATH} && pwd)
echo 프로젝트 위치: $REAL_PATH
cd $REAL_PATH

echo "====================================="
echo""
echo "   ## 42testers-gnl test will start "
echo""
echo "====================================="
read -p "  V^^v 42SEOUL v^^V"
echo "====================================="
echo ""

SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'

## 42testers-gnl
git clone https://github.com/Mazoise/42TESTERS-GNL.git 42testers-gnl
cd 42testers-gnl
bash all_tests_with_bonus.sh
cd ..

echo "====================================="
echo""
echo "   ## gnl_lover test will start "
echo""
echo "====================================="
read -p "  V^^v 42SEOUL v^^V"
echo "====================================="
echo ""

SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'
### gnl_lover
git clone https://github.com/charMstr/GNL_lover.git gnl-lover
cp get_next_line* gnl-lover/copy_in_here_GNL_files
cd gnl-lover
sh GNL_lover.sh
cd ..

echo "====================================="
echo""
echo "   ## gnlkiller test will start "
echo""
echo "====================================="
read -p "  V^^v 42SEOUL v^^V"
echo "====================================="
echo ""

SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'

### gnlkiller
git clone https://github.com/DontBreakAlex/gnlkiller.git
cd gnlkiller
cp ../get_next_line.c .
cp ../get_next_line_utils.c .
cp ../get_next_line.h .
./run.sh;
cd ..
# #############???? what is this tester.      지우자. 뭔지 모르겠다.
echo "====================================="
echo""
echo "   ## gnlkiller2 test will start "
echo""
echo "====================================="
read -p "  V^^v 42SEOUL v^^V"
echo "====================================="
echo ""

SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'

### gnlkiller2
git clone https://github.com/Sherchryst/gnlkiller.git gnlkiller2
cd gnlkiller2
cp ../get_next_line.c .
cp ../get_next_line_utils.c .
cp ../get_next_line.h .
chmod +x test.sh
./test.sh;
cd ..
# ###   ????왠 안됨
echo "====================================="
echo""
echo "   ## TEST-42 test will start "
echo""
echo "====================================="
read -p "  V^^v 42SEOUL v^^V"
echo "====================================="
echo ""

SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'

### TEST-42
git clone https://github.com/PandaCoustik/Test-42.git
cd Test-42/test_gnl
chmod +x test.sh
./test.sh
cd ../..

echo "====================================="
echo""
echo "   ## gnlTester test will start "
echo""
echo "====================================="
read -p "  V^^v 42SEOUL v^^V"
echo "====================================="
echo ""

SECONDS=0;
while sleep .5 && ((SECONDS <= 5)); do
    printf '\r%s: %2d' "Testing will start soon" "$((5-SECONDS))"
done
printf '\n'

### gnlTester (2019+)
git clone https://github.com/Tripouille/gnlTester.git
cd gnlTester
# make m # 필수 파트만 실행
# make b # 보너스 파트만 실행
make a # 필수와 보너스 모두 실행
cd ..