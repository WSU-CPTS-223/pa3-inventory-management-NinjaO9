#include "libs.h"
#ifndef PROD_DATA_H
#define PROD_DATA_H

class ProductData
{

    public:

    ProductData(string nUID, string nPN, string nBN, string nAsin, string nCategories, string nUEC, string nLPrice, string nSPrice, string nQuant, string nModNum, string nAbtProd, string nProdSpec, string nTechDet, string nShipW, string nProdDim, string nImage, string nVars, string nSku, string nProdUrl, string nDims, string nColor, string nIngredients, string nDirToUse, string nIsAmaSell, string nSQuanVar, string nProdDesc)
    : _UniqId(nUID), _ProductName(nPN), _BrandName(nBN), _Asin(nAsin), _Categories(nCategories), _UpcEanCode(nUEC), _ListPrice(nLPrice), _SellingPrice(nSPrice), _Quantity(nQuant), _ModelNumber(nModNum), _AboutProduct(nAbtProd), _ProductSpecifications(nProdSpec), _TechnicalDetails(nTechDet), _ShippingWeight(nShipW), _ProductDimensions(nProdDim), _Image(nImage), _Variants(nVars), _Sku(nSku), _ProductUrl(nProdUrl), _Dimensions(nDims), _Color(nColor), _Ingredients(nIngredients), _DirectionToUse(nDirToUse), _IsAmazonSeller(nIsAmaSell), _SizeQuantityVariant(nSQuanVar), _ProductDescription(nProdDesc){}
    // Long ass constructor of doom

    string getUniqId() const {return _UniqId;}

    string getProductName() const {return _ProductName;}

    string getBrandName() const {return _BrandName;}

    string getAsin() const {return _Asin;}

    string getCategories() const {return _Categories;}

    string getUpcEanCode() const {return _UpcEanCode;}

    string getListPrice() const {return _ListPrice;}

    string getSellingPrice() const {return _SellingPrice;}

    string getQuantity() const {return _Quantity;}

    string getModelNumber() const {return _ModelNumber;}

    string getAbout() const {return _AboutProduct;}

    string getProduceSpecs() const {return _ProductSpecifications;}

    string getTechDetails() const {return _TechnicalDetails;}

    string getShippingWeight() const {return _ShippingWeight;}

    string getProdDimenstions() const {return _ProductDimensions;}

    string getImage() const {return _Image;}

    string getVariants() const {return _Variants;}

    string getSku() const {return _Sku;}

    string getProdUrl() const {return _ProductUrl;}

    string getStock() const {return _Stock;}

    string getProdDetails() const {return _ProductDetails;}

    string getDimensions() const {return _Dimensions;}

    string getColor() const {return _Color;}

    string getIngredients() const {return _Ingredients;}

    string getDirectionToUse() const {return _DirectionToUse;}

    string getIsAmazonSeller() const {return _IsAmazonSeller;}

    string getSizeQuantityVariant() const {return _SizeQuantityVariant;}

    string getProductDescription() const {return _ProductDescription;}


    private:
    // _AboutProduct, _Categories <- Might be lists
    const string _UniqId, _ProductName, _BrandName,
     _Asin, _Categories, _UpcEanCode, _ListPrice, 
     _SellingPrice, _Quantity, _ModelNumber, _AboutProduct, 
     _ProductSpecifications, _TechnicalDetails, _ShippingWeight,
      _ProductDimensions, _Image, _Variants, _Sku, _ProductUrl, 
      _Stock, _ProductDetails, _Dimensions, _Color, _Ingredients, 
      _DirectionToUse, _IsAmazonSeller, _SizeQuantityVariant, 
      _ProductDescription;

};

/*
ostream& operator<<(ostream& lhs, ProductData& rhs)
{
    lhs << "Uniqe ID: " << rhs.getUniqId() << " Product Name: " << rhs.getProductName() << endl;
    return lhs;
}
    */

#endif