//BiquadFilter.h
#pragma once

#include <vector>

namespace BiquadFilter
{
	//�f�B�W�^���t�B���^���ۃN���X
	class Filter{
	public:
		virtual ~Filter();
		void filtering(std::vector<double> *x);
	protected:
		void alloc();

	protected:
		//�t�B���^�W��
		std::vector<double> a;
		std::vector<double> b;
	};

	//���[�p�X�t�B���^
	class LPFilter : public Filter{
	public:
		LPFilter(double cutoff, double Q);
	private:
		double cutoff; //���K�����ꂽ�J�b�g�I�t���g��(freq/samplerate)
		double Q;
	};

	//�n�C�p�X�t�B���^
	class HPFilter : public Filter{
	public:
		HPFilter(double cutoff, double Q);
	private:
		double cutoff; //���K�����ꂽ�J�b�g�I�t���g��(freq/samplerate)
		double Q;
	};

	//�o���h�p�X�t�B���^
	class BPFilter : public Filter{
	public:
		BPFilter(double low_edge, double high_edge);
	private:
		double low_edge;
		double high_edge;
	};

	//�m�b�`�t�B���^�[
	class NTFilter : public Filter{
	public:
		NTFilter(double low_edge, double high_edge);
	private:
		double low_edge;
		double high_edge;
	};

	//���[�V�F���t�t�B���^
	class LSFilter : public Filter{
	public:
		LSFilter(double cutoff, double Q, double gain);
	private:
		double cutoff;
		double Q;
		double gain;
	};

	//�n�C�V�F���t�t�B���^
	class HSFilter : public Filter{
	public:
		HSFilter(double cutoff, double Q, double gain);
	private:
		double cutoff;
		double Q;
		double gain;
	};

	//�s�[�L���O�t�B���^
	class PKFilter : public Filter{
	public:
		PKFilter(double low_edge, double high_edge, double gain);
	private:
		double low_edge;
		double high_edge;
		double gain;
	};

	//�I�[���p�X�t�B���^
	class APFilter : public Filter{
	public:
		APFilter(double cutoff, double Q);
	private:
		double cutoff;
		double Q;
	};
}