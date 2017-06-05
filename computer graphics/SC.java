package jk3.smh;

import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Point;

public class SC extends Applet {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int xR,xL,yT,yB;   
	Point [] p;
	Point []temp ;
	public SC(){
		init();
	}
	public void paint(Graphics g){
		
		for(int i=1;i<=7;i++){
			Sutherland_cohen(g,p[i].x,p[i].y,p[i-1].x,p[i-1].y);
			p[i] = temp[i];
			System.out.println(temp[i].x+"  "+temp[i].y);
			//g.drawLine(p[i].x,p[i].y,p[i-1].x,p[i-1].y);
		}
		//g.drawLine(p[1].x,p[1].y,p[4].x,p[4].y);
		g.drawRect(100, 100, 100, 100);
		//g.drawLine(x0, y0, x2, y2);
	}
	public int code(float x,float y){
		int c  = 0;
		if(x < xL) 
			c = c|1;
		else if(x > xR) 
			c = c|2;
		if(y < yB) 
			c = c|4;
		else if(y > yT) 
			c = c|8;
		return c;
	}
	public void Sutherland_cohen(Graphics g,float x0,float y0,float x2,float y2){
		int c1,c2,c;
		float x,y,wx,wy;
		boolean accpet = false ,done = false;
		c1 = code(x0,y0);
		c2 = code(x2,y2);
		do{
			if((c1|c2) == 0){ 		// 判断这条线段完全在裁剪矩形内部  c1 c2 全部为0   例如线段AB
				accpet = true;
				done = true;
			}else if((c1&c2) != 0){	// 判断这条线是否在四个方向的一侧 完全在一侧  就是完全不在裁剪矩形框里面 例如 线段CD
				done = true;
			}else{					// 剩余其他的情况
				c = c1;
				if(c == 0) c = c2;	// 第一个点在裁剪矩形框内部  
				wx = x2 - x0;
				wy = y2 - y0;  		
				if((c&8) == 8){		// 判断c & (8,4,2,1) 判断线段端点具体方位   裁剪部分
					x = x0 + wx*(yT-y0)/wy;
					y = yT;
				}else if((c&4) == 4){
					x = x0+ wx*(yB-y0)/wy;
					y = yB;
				}else if((c&1) == 1){
					y = y0 + wy*(xL-x0)/wx;
					x = xL;
				}else{
					y = y0 + wx*(xR-x0)/wy;
					x = xR;
				}
				if(c == c1){
					x0 = x;
					y0 = y;
					c1 = code(x0,y0);
				}else{
					x2 = x;
					y2 = y;
					c2 = code(x2,y2);
				}
			}	
		}while(done == false);
		if(accpet){
			g.drawLine((int)x0,(int)y0,(int)x2,(int)y2);
		}
	}
	public void init(){
		p = new Point[8];
		temp = new Point[8];
		p[0] = new Point(120,180);
		p[1] = new Point(170,300);
		p[2] = new Point(270,300);
		p[3] = new Point(270,150);
		p[4] = new Point(130,120);
		p[5] = new Point(220,170);
		p[6] = new Point(220,250);
		p[7] = new Point(120,180);
		temp[0] = new Point(120,180);
		temp[1] = new Point(170,300);
		temp[2] = new Point(270,300);
		temp[3] = new Point(270,150);
		temp[4] = new Point(130,120);
		temp[5] = new Point(220,170);
		temp[6] = new Point(220,250);
		temp[7] = new Point(120,180);
		xL = 100;
		xR = 200;
		yT = 200;
		yB = 100;
	}
}
