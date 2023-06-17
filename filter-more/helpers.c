#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            float average = 0;
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            average = (int) round(average);
            //nur ganze mit 0xff
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE save[height][width];
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            save[i][width-(j+1)] = image[i][j];
        }
    }
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            image[i][j] = save[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE save[height][width];

    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            //betrachte ein pixel
            int y[3] = {i-1, i, i+1};
            int x[3] = {j-1, j, j+1};

            double rgbsum [3] = {0,0,0};
            int n = 0;

            for (int k= 0; k < 3; k++)
            {
                for (int l= 0; l < 3; l++)
                {
                    //betrachte 3x3 block um pixel
                    if (y[k] >= 0 && y[k] < height && x[l] >= 0 && x[l] < width)
                    {
                        //addiere alle existenten farben im block
                        rgbsum[0] += image[y[k]][x[l]].rgbtBlue;
                        rgbsum[1] += image[y[k]][x[l]].rgbtGreen;
                        rgbsum[2] += image[y[k]][x[l]].rgbtRed;
                        n++; //divident
                    }
                }
            }
            save[i][j].rgbtBlue = round((rgbsum[0] / n));
            save[i][j].rgbtGreen = round((rgbsum[1] / n));
            save[i][j].rgbtRed = round((rgbsum[2] / n));
        }
    }
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            image[i][j].rgbtBlue = save[i][j].rgbtBlue;
            image[i][j].rgbtGreen = save[i][j].rgbtGreen;
            image[i][j].rgbtRed = save[i][j].rgbtRed;
        }
    }
    return;
}







// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE save[height][width];
    RGBTRIPLE temp[height][width];
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
          temp[i][j].rgbtBlue = image[i][j].rgbtBlue;// copying dosent help
          temp[i][j].rgbtRed = image[i][j].rgbtRed;
          temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            int y[] = {i-1, i, i+1};
            int x[] = {j-1, j, j+1};

            int gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
            int gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
            int count = 0;

            float xblue = 0, xgreen = 0, xred = 0, yblue = 0, ygreen = 0, yred = 0;

            for (int k= 0; k < 3; k++)
            {
                for (int l= 0; l < 3; l++)
                {//loop 3x3
                    if (y[k] < 0 || y[k] >= height || x[l] < 0 || x[l] >= width)
                    {
                        temp[y[k]][x[l]].rgbtBlue = 0;
                        temp[y[k]][x[l]].rgbtGreen = 0;
                        temp[y[k]][x[l]].rgbtRed = 0;
                    }
                    xblue += (temp[y[k]][x[l]].rgbtBlue * gx[count]);
                    xgreen += (temp[y[k]][x[l]].rgbtGreen * gx[count]);
                    xred += (temp[y[k]][x[l]].rgbtRed * gx[count]);

                    yblue += (temp[y[k]][x[l]].rgbtBlue * gy[count]);
                    ygreen += (temp[y[k]][x[l]].rgbtBlue * gy[count]);
                    yred += (temp[y[k]][x[l]].rgbtBlue * gy[count]);

                    count++;
                }
                count++;
            }
            int blue = round(sqrt((xblue*xblue)+(yblue*yblue)));
            int green = round(sqrt((xgreen*xgreen)+(ygreen*ygreen)));
            int red = round(sqrt((xred*xred)+(yred*yred)));

            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (red > 255)
            {
                red = 255;
            }
            save[i][j].rgbtBlue = blue;
            save[i][j].rgbtGreen = green;
            save[i][j].rgbtRed = red;
        }
    }
    for (int i= 0; i < height; i++)
    {
        for (int j= 0; j < width; j++)
        {
            image[i][j].rgbtBlue = save[i][j].rgbtBlue;
            image[i][j].rgbtGreen = save[i][j].rgbtGreen;
            image[i][j].rgbtRed = save[i][j].rgbtRed;
        }
    }
    return;
}


//            long bgx = 0;
  //          long ggx = 0;
    //        long rgx = 0;
      //                  //for gy

        //    mcount = 0;
          //  long bgy = 0;
            //long ggy = 0;
            //long rgy = 0;
//            for (int k= 0; k < 3; k++)
  //          {
    //            for (int l= 0; l < 3; l++)
      //          {//loop 3x3
        //            long blue = image[y[k]][x[l]].rgbtBlue;
          //          long green = image[y[k]][x[l]].rgbtGreen;
            //        long red = image[y[k]][x[l]].rgbtRed;
              //      bgy += (blue * multigy[mcount]);
                //    ggy += (green * multigy[mcount]);
                  //  rgy += (red * multigy[mcount]);
//                    mcount++;
  //              }
    //            mcount++;
      //      }
        //    double bround = round(sqrt((bgx*bgx)+(bgy*bgy)));
          //  double ground = round(sqrt((ggx*ggx)+(ggy*ggy)));
            //double rround = round(sqrt((rgx*rgx)+(rgy*rgy)));
//            if (bround > 255)
  //          {
    //          save[i][j].rgbtBlue = 255;
      //      }
        //    else
          // {
           //   save[i][j].rgbtBlue = bround;
//            }
  //          if (ground > 255)
    //        {
      //        save[i][j].rgbtGreen = 255;
        //    }
          //  else
//            {
  //            save[i][j].rgbtGreen = ground;
    //        }
      //      if (rround > 255)
        //    {
          //    save[i][j].rgbtRed = 255;
            //}
//            else
  //          {
    ///          save[i][j].rgbtRed = rround;
       ///     }
//






//
//                    int p[3][9];
  //                  for (int m= 0; m < 3; m++)
//
  //                      if (k==0 && l==0)
    //                    {
      //                  p[m][0]= image[i][j].rgbtBlue*(-1);
        //                }
          //              else if (k==0 && l==1)
            //            {
              //          p[m][1]= image[i][j].rgbtBlue*(0);
                //        }
                  //      else if (k==0 && l==2)
                    //    {
                      //  p[m][2]= image[i][j].rgbtBlue*(1);
                        //}
//                        else if (k==1 && l==0)
  //                      {
    //                    p[m][3]= image[i][j].rgbtBlue*(-2);
      //                  }
        //                else if (k==1 && l==1)
          //              {
            //            p[m][4]= image[i][j].rgbtBlue*(0);
              //          }
                //        else if (k==1 && l==2)
                  //      {
                    ////    p[m][5]= image[i][j].rgbtBlue*(2);
                        //}
 //                       else if (k==2 && l==0)
   //                     {
     //                   p[m][6]= image[i][j].rgbtBlue*(-1);
       //                 }
         //               else if (k==2 && l==1)
           //             {
             //           p[m][7]= image[i][j].rgbtBlue*(0);
               //         }
                 //       else if (k==2 && l==2)
                   //     {
                     //   p[m][8]= image[i][j].rgbtBlue*(1);