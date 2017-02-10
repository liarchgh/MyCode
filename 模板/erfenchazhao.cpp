void (template * l, template * r, template tg, template * ans){
   while(l <= r){
      template * mid = (l + r) / 2;
      if(*mid < tg){
         l = mid + 1;
      }
      else if(*mid > tg){
         r = mid - 1;
      }
      else{
         ans = mid;
         return ;
      }
   }
}
