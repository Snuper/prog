delay = 100
s = 1
s = new Array()
for(i = 1; i < 11; i++) {
   s[i] = new Image()
   s[i].src = "s" + i + ".gif"
   }
function animate() {
   document.animation.src = s[imageNum].src
   imageNum++;   
   if(imageNum > 10) {
   imageNum = 1
   }
}
function slower() {
   delay+=10
   if(delay > 4000) delay = 4000
}
function faster() {
   delay-=10
   if(delay < 0) delay = 0
}