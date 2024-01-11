clc
clear
close all
%%

srcFile=dir('D:\iroads\Daylight\JPEGImages\*.jpg');
for i=1:length(srcFile)
    filename=strcat('D:\iroads\Daylight\JPEGImages\',srcFile(i).name);
    Im=imread(filename);
    
im_cop1=rgb2gray(Im);

%%
im_cop1_filt = medfilt2(im_cop1);
%%
[n,m]=size(im_cop1_filt);
average=mean(mean(im_cop1_filt));
for i=1:n
    for j=1:m
        if im_cop1_filt(i,j)>=(average)
            im_cop1_filt(i,j)=im_cop1_filt(i,j);
        else
            im_cop1_filt(i,j)=0;
        end
    end
end
%%

x=[30,220,390,520];
y=[360,260,260,360];

mask=poly2mask(x,y,n,m);

im_cop1_filt=double(im_cop1_filt);
im_cop1_filt=im_cop1_filt.*mask;
%%
im_cop1_filt=edge(im_cop1_filt,'sobel');

%%
[H,T,R] = hough(im_cop1_filt,'RhoResolution',1,'Theta',-90:0.5:89);
P = houghpeaks(H,4,'Threshold',ceil(0.5*max(H(:))));

lines = houghlines(im_cop1_filt,T,R,P,'MinLength', 1, 'FillGap',0.8*n);
%%
max_len = 0;
imshow(Im), hold on
for k = 1:length(lines)
   xy = [lines(k).point1; lines(k).point2];
   plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');
end
drawnow()
hold off


end
