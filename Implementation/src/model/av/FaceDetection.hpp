//File: FaceDetection.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef FACEDETECTION_HPP
#define FACEDETECTION_HPP

#include <src/model/av/AV.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            class FaceDetection
                    : public AV
            {
                public:
                    FaceDetection();

                    virtual std::string getProcessorType() const;
                    virtual void setProcessorType(const std::string& type);

                    virtual double getScaleFactor() const;
                    virtual void setScaleFactor(double factor);
                    virtual int getNeightbors() const;
                    virtual void setNeightbors(int neightbors);
                    virtual int getWidth() const;
                    virtual void setWidth(int width);
                    virtual int getHeight() const;
                    virtual void setHeight(int height);

                private:
                    std::string mProcessorType;
                    double mScaleFactor;
                    int mNeightbors;
                    int mWidth;
                    int mHeight;
            };
        }
    }
}

#endif // FACEDETECTION_HPP
